#include "../../includes/minishell.h"

void	execute_command(char *argv, char **possible_paths, char **envp)
{
	char	*cmd;
	char	**cmd_flags;
	int		idx;

	idx = 0;
	cmd_flags = ft_split(argv, ' ');
	while (possible_paths[idx] != NULL)
	{
		cmd = ft_strjoin(possible_paths[idx], cmd_flags[0]);
		execve(cmd, cmd_flags, envp);
		free(cmd);
		idx++;
	}
	ft_free(possible_paths);
	perror(cmd_flags[0]);
	ft_free(cmd_flags);
	exit(1);
}

int	spawn_process(t_ms_data *data, char **possible_paths, char *envp[])
{
	int		fd[2];
	int		check;

	check = ft_validity_check(pipe(fd), "Piping error");
	if (check == 0)
		return (1);
	data->p_id = fork();
	check = ft_validity_check(data->p_id, "Forking error");
	if (check == 0)
		return (2);
	if (data->p_id == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute_command(argv[0], possible_paths, envp);
	}
	dup2(fd[0], STDIN_FILENO);
	waitpid(data->p_id, NULL, 1);
	close(fd[1]);
	return (0);
}

int	here_doc_func(t_ms_data *data, int fd_in)
{
	char	*buf;


	buf = malloc(sizeof(char) * (ft_strlen(data->limiter) + 1));

	while (1)
	{
		read(fd_in, buf, 1);
	}	
}


int	command_prep_in(t_ms_data *data)
{
	int	in;

	in = open(data->in_file, O_RDONLY);
	if (!ft_validity_check(in, data->in_file))
		return (-1);
	dup2(in, STDIN_FILENO);
	return (in);
}

int	command_prep_out(t_ms_data *data)
{
	int	out;

	if (data->output_type == 1)
	{
		out = open(data->out_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (!ft_validity_check(out, data->out_file))
			return (-1);
	}
	if (data->output_type == 2)
	{
		out = open(data->out_file, O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (!ft_validity_check(out, data->out_file))
			return (-1);
	}
	dup2(out, STDOUT_FILENO);
	return (out);
}

int	command_exec(t_ms_data *data)
{
	int		fd_input;
	int		fd_out;
	int		counter;
	char	**possible_paths;

	fd_input = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	if (data->in_file != NULL)
		fd_input = command_prep_in(data);
	if (fd_input < 0)
		return (1);
	if (data->here_doc == true)
		here_doc_func(data, fd_input);
	if (data->out_file != NULL)
		fd_out = command_prep_out(data);
	if (fd_input < 0)
		return (2);
	possible_paths = get_paths(data->env);
	counter = 0;
	while (counter < data->command_amt - 1)
	{
		spawn_process(data->commands[counter], possible_paths, data->env);
		counter++;
	}
	execute_command(argv[argc - 2], possible_paths, data->env);
	close_descriptors(2, fd_out, fd_input);
	return (0);
}