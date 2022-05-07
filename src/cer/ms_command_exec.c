#include "../../includes/minishell.h"

int	cleanup_command(int cleanup_case, int in_fd, int  out_fd)
{
	int	fd[2];

	if (cleanup_case == 1 && in_fd > 2)
		close(in_fd);
	if (cleanup_case == 2)
	{
		if (in_fd > 2)
			close(in_fd);
		if (out_fd > 2)
			close(out_fd);
	}
	pipe(fd);
	close(fd[1]);
	return (fd[0]);
}

int	child_proccess_managing_outfds(int out_fd, int *pipe_fd)
{
	int	check;

	if (out_fd == -1 || out_fd == -2)
	{
		check = dup2(pipe_fd[1], STDOUT_FILENO);
		if (check < 0)
			return (print_error_message("dup2", NULL));
		return (pipe_fd[1]);
	}
	check = dup2(out_fd, STDOUT_FILENO);
	if (check < 0)
		return (print_error_message("dup2", NULL));
	check = close(pipe_fd[1]);
	if (check < 0)
		return (print_error_message("close", NULL));
	return (out_fd);
}

int	child_proccess_managing_infds(int in_fd, int *pipe_fd, t_ms_data *data)
{
	int	check;

	if ((in_fd == -1 || in_fd == -2) && data->i > 0)
	{
		printf("%d\n", data->i);
		check = dup2(pipe_fd[0], STDIN_FILENO);
		if (check < 0)
			return (print_error_message("dup2", NULL));
		return (pipe_fd[0]);
	}
	if (in_fd > 0)
	{
		check = dup2(in_fd, STDIN_FILENO);
		if (check < 0)
			return (print_error_message("dup2", NULL));
		check = close(pipe_fd[0]);
		if (check < 0)
			return (print_error_message("close", NULL));
		return (in_fd);
	}
	return (0);
}

void	child_process_prep(t_ms_data *data, int in_fd, int out_fd, int *pipe_fd)
{
	int	in;
	int	out;

	printf("child in fd == %d out fd == %d pipe in == %d pipe out == %d\n"  ,in_fd,  out_fd,  pipe_fd[0], pipe_fd[1]);
	in = child_proccess_managing_infds(in_fd, pipe_fd, data);
	if (in < 0)
		exit(-1);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	if (out < 0)
		exit(-1);
	printf("this is the in fd for child == %d\nthis is the out fd for child == %d\n", in , out);
	printf("this is the command \n\n%s\n\n", data->command[data->i].cmd_flags[0]);
	execve(data->command[data->i].cmd_flags[0],
		data->command[data->i].cmd_flags, data->env);
	print_error_message("execve", data->command[data->i].cmd_flags[0]);
	close(in);
	close(out);
	exit(-1);
}

int	fork_and_execute(t_ms_data *data, int in_fd, int out_fd, int i)
{
	int	pipe_fd[2];
	int	id;
	int	w_status;

	if (pipe(pipe_fd) == -1)
		return (print_error_message("pipe", NULL));
	id = fork();
	if (id == -1)
		return (print_error_message("fork", NULL));
	if (id == 0)
		child_process_prep(data, in_fd, out_fd, pipe_fd);
	wait(&w_status);
	data->exit_codes = w_status;
	close(pipe_fd[1]);
	if (in_fd > 2)
		close(in_fd);
	printf("%d %d close fds\n", pipe_fd[1], in_fd);
	printf("%d\n", out_fd);
	if (out_fd > 2)
		close(out_fd);
	printf("pipe_fd 0 in parent == %d \n", pipe_fd[0]);
	return (pipe_fd[0]);
}

char	*ms_find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	return (env[i] + 5);
}

int	execute_exeption_command(t_ms_data *data, int in_fd, int out_fd, int *pipe_fd )
{
	char	*cmd;
	int		in;
	int		out;

	in = child_proccess_managing_infds(in_fd, pipe_fd, data);
	if (in < 0)
		exit(-1);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	if (out < 0)
		exit(-1);
	cmd = data->command[data->i].cmd_flags[0];
	if (ft_strncmp(cmd, "echo", 6) == 0)
		return (ms_echo(data->command[data->i].cmd_flags));
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (ms_pwd());
	return (ms_env(data->command[data->i].cmd_flags, data->env));
}

//env pwd echo 
int	non_fork_exception(t_ms_data *data)
{
	char	*cmd;

	cmd = data->command[data->i].cmd_flags[0];
	if (ft_strncmp(cmd, "exit", 6) == 0)
		ms_exit(data);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (ms_cd(data->command[data->i].cmd_flags[1],
				ms_find_home(data->env), data));
	if (ft_strncmp(cmd, "export", 8) == 0)
		return (ms_export(data));
	if (ft_strncmp(cmd, "unset", 7) == 0)
		return (ms_unset(data));
	return (-1);
}

int	fork_for_exeption_command(t_ms_data *data, int in_fd, int out_fd)
{
	int	pipe_fd[2];
	int	id;
	int	w_status;
	int	check;

	check = non_fork_exception(data);
	if (check > -1)
	{
		data->exit_codes = check;
		return (0);
	}
	if (pipe(pipe_fd) == -1)
		return (print_error_message("pipe", NULL));
	id = fork();
	if (id == -1)
		return (print_error_message("fork", NULL));
	if (id == 0)
		exit(execute_exeption_command(data, in_fd, out_fd, pipe_fd));
	wait(&w_status);
	data->exit_codes = w_status;
	close(pipe_fd[1]);
	close(in_fd);
	if (out_fd != STDOUT_FILENO)
		close(out_fd);
	return (pipe_fd[0]);
}

//change returns into fds and exit codes directly into data.exit_codes

char	*find_exeption_command(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 6) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "export", 8) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "unset", 7) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (cmd);
	if (ft_strncmp(cmd, "exit", 6) == 0)
		return (cmd);
	return (NULL);
}

int	command_exec_prep(t_ms_data *data, int i, int in_fd, int out_fd)
{
	char	*execute_path;

	if (data->command[i].input[0])
		in_fd = prep_input_fd(data, i, in_fd);
	if (in_fd < 0)
		return (cleanup_command(0, 0, 0));
	if (data->command[i].input[0] == NULL && i < 1)
		in_fd = -2;
	if (data->command[i].output[0])
		out_fd = prep_output_fd(data, i, STDOUT_FILENO);
	if (out_fd < 0)
		return (cleanup_command(1, in_fd, 0));
	if (data->command[i].output[0] == NULL && i < (data->command_amt - 1))
		out_fd = -2;
	if (data->command[i].cmd_flags[0] == NULL)
		return (cleanup_command(2, in_fd, out_fd));
	if (find_exeption_command(data->command[i].cmd_flags[0]) != NULL)
		return (fork_for_exeption_command(data, in_fd, out_fd));
	execute_path = find_executable_path(data->command[i].cmd_flags[0],
			data->env, data);
	if (execute_path == NULL)
		return (cleanup_command(2, in_fd, out_fd));
	if (data->command[i].cmd_flags[0] != execute_path)
		free(data->command[i].cmd_flags[0]);
	data->command[i].cmd_flags[0] = execute_path;
	printf("execute_path == %s\n", execute_path);
	return (fork_and_execute(data, in_fd, out_fd, i));
}

int	command_exec_loop(t_ms_data *data)
{
	int	pipe_fd;

	pipe_fd = STDIN_FILENO;
	data->i = 0;
	while (data->i < data->command_amt)
	{
		pipe_fd = command_exec_prep(data, data->i, pipe_fd, STDOUT_FILENO);
		// if (pipe_fd < 0)
		// 	pipe_fd = STDIN_FILENO;
		data->i++;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
