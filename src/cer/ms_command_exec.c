#include "../../includes/minishell.h"


int	cleanup_command(int	cleanup_case, int in_fd)
{
	if (cleanup_case == 1)
		close(in_fd);
	return (-1);
}

int	command_exec_prep(t_ms_data *data, int i, int in_fd)
{
	int		out_fd;
	char	*execute_path;

	if (data->command[i].input[0])
		in_fd = prep_input_fd(data, i);
	if (in_fd < 0)
		return (cleanup_command(0, 0));
	if (data->command[i].output[0])
		out_fd = prep_output_fd(data, i);
	if (out_fd < 0)
		return (cleanup_command(1, in_fd));
	execute_path = find_executable_path();



// THIS IS WHERE I AM AT RIGHT NOW





	if (!execute_path)
		return (cleanup_command(1, in_fd));
}

int	command_exec_loop(t_ms_data *data)
{
	int	i;
	int	pipe_fd;

	i = 0;
	pipe_fd = STDIN_FILENO;
	while (i < data->command_amt)
	{
		pipe_fd = command_exec_prep(data, i, pipe_fd);
		if (pipe_fd < 0)
			pipe_fd = STDIN_FILENO;
		i++;
	}
	return (0);
}
