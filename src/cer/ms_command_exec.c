#include "../../includes/minishell.h"

int	command_exec_prep(t_ms_data *data, int i, int in_fd)
{
	if (data->command[i].reddir_in[0])
		in_fd = open_and_check_access(data->command[i].reddir_in[0], R_OK, false, false);
	if (in_fd < 0)
		print_error_message();
}

int	command_exec_loop(t_ms_data *data)
{
	int	i;
	int	pipe_fd;

	i = 0;
	pipe_fd = STDIN_FILENO;
	while (i < data->command_amt)
	{
		pipe_fd = command_exec(data, i, pipe_fd);
		if (pipe_fd < 0)
			return (-1);
		i++;
	}
	return (0);
}





// int	command_exec(t_ms_data *data, int i, int pipe_fd)
// {
// 	int		fd_input;
// 	int		fd_out;

// 	if (i != 0)
// 		fd_input = pipe_fd;
// 	if (data->command->reddir_in[0] != NULL)
// 		fd_input = command_prep_in(data, data->command->reddir_in);
// 	if (fd_input < 0)
// 		return (1);
// 	fd_out = STDOUT_FILENO;
// 	if (data->command->reddir_in[0] != NULL)
// 		fd_input = command_prep_in(data);
// 	if (fd_input < 0)
// 		return (1);
// 	if (data->here_doc == true)
// 		here_doc_func(data, fd_input);
// 	if (data->out_file != NULL)
// 		fd_out = command_prep_out(data);
// 	if (fd_input < 0)
// 		return (2);
// }