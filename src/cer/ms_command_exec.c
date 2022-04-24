#include "../../includes/minishell.h"


int	cleanup_command(int cleanup_case, int in_fd)
{
	if (cleanup_case == 1)
		close(in_fd);
	return (-1);
}

int	child_proccess_managing_outfds(int out_fd, int *pipe_fd)
{
	int	check;

	printf("inside child managing outfd == %d pipe[0] == %d pipe [1] == %d \n", out_fd, pipe_fd[0], pipe_fd[1]);
	if (out_fd == -1)
	{
		printf("HELLO :)\n");
		check = dup2(pipe_fd[1], STDOUT_FILENO);
		printf("HELLO :)\n");
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

int	child_proccess_managing_infds(int in_fd, int *pipe_fd)
{
	int	check;

	if (in_fd == -1)
	{
		check = dup2(pipe_fd[0], STDIN_FILENO);
		if (check < 0)
			return (print_error_message("dup2", NULL));
		return (pipe_fd[0]);
	}
	check = dup2(in_fd, STDIN_FILENO);
	if (check < 0)
		return (print_error_message("dup2", NULL));
	check = close(pipe_fd[0]);
	if (check < 0)
		return (print_error_message("close", NULL));
	return (in_fd);
}

void	child_process_prep(t_ms_data *data, int in_fd, int out_fd, int *pipe_fd)
{
	int	check;
	int	in;
	int	out;

	printf("hello from childprocess()\n");
	in = child_proccess_managing_infds(in_fd, pipe_fd);
	printf("hello from after input fd management\n");
	if (in < 0)
		exit(-1);
	printf("child process prep () in_fd == %d out_fd == %d pipe_in == pipe %d out == %d\n", in_fd, out_fd, pipe_fd[0], pipe_fd[1]);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	if (out < 0)
		exit(-1);
	execve(data->command[data->i].cmd_flags[0],
		data->command[data->i].cmd_flags, data->env);
	print_error_message("execve", NULL);
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
	printf("parent process successfully waited \n");
	//*(data->exit_codes) = w_status;    how do i write the int into here?














	printf("parent process successfully stored exit code \n");
	close(pipe_fd[1]);
	printf("test_1\n");
	close(in_fd);
	printf("test_2\n");
	if (out_fd != STDOUT_FILENO)
		close(out_fd);
	printf("test_3\n");
	return (pipe_fd[0]);
}

int	command_exec_prep(t_ms_data *data, int i, int in_fd)
{
	int		out_fd;
	char	*execute_path;

	if (data->command[i].input[0])
		in_fd = prep_input_fd(data, i, in_fd);
	if (in_fd < 0)
		return (cleanup_command(0, 0));
	in_fd = STDIN_FILENO;
	if (data->command[i].input[0] == NULL && i > 0)
		in_fd = -1;
	if (data->command[i].output[0])
		out_fd = prep_output_fd(data, i, STDOUT_FILENO);
	if (out_fd < 0)
		return (cleanup_command(1, in_fd));
	out_fd = STDOUT_FILENO;
	if (data->command[i].output[0] == NULL && i < (data->command_amt - 1))
		out_fd = -1;
	execute_path = find_executable_path(data->command[i].cmd_flags[0],
			data->env);
	if (execute_path == NULL)
		return (cleanup_command(1, in_fd));
	free(data->command->cmd_flags[0]);
	data->command->cmd_flags[0] = execute_path;
	return (fork_and_execute(data, in_fd, out_fd, i));
}

int	command_exec_loop(t_ms_data *data)
{
	int	pipe_fd;

	pipe_fd = STDIN_FILENO;
	data->i = 0;
	while (data->i < data->command_amt)
	{
		pipe_fd = command_exec_prep(data, data->i, pipe_fd);
		printf("command execution is finished \n");
		if (pipe_fd < 0)
			pipe_fd = STDIN_FILENO;
		data->i++;
	}
	return (0);
}