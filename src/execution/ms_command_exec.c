/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:28 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 18:18:57 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	command_exec_prep(t_ms_data *data, int i, int in_fd, int out_fd)
{
	char	*x_p;

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
	x_p = find_executable_path(data->command[i].cmd_flags[0], data->env, data);
	if (x_p == NULL)
		return (cleanup_command(2, in_fd, out_fd));
	if (data->command[i].cmd_flags[0] != x_p)
		free(data->command[i].cmd_flags[0]);
	data->command[i].cmd_flags[0] = x_p;
	return (fork_and_execute(data, in_fd, out_fd));
}

int	command_exec_loop(t_ms_data *data)
{
	int	pipe_fd;

	pipe_fd = STDIN_FILENO;
	data->i = 0;
	while (data->i < data->command_amt)
	{
		pipe_fd = command_exec_prep(data, data->i, pipe_fd, STDOUT_FILENO);
		data->i++;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
