/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_and_executing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:29:20 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:30:30 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	in = child_proccess_managing_infds(in_fd, pipe_fd, data);
	if (in < 0)
		exit(-1);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	if (out < 0)
		exit(-1);
	execve(data->command[data->i].cmd_flags[0],
		data->command[data->i].cmd_flags, data->env);
	print_error_message("execve", data->command[data->i].cmd_flags[0]);
	close(in);
	close(out);
	exit(-1);
}

int	fork_and_execute(t_ms_data *data, int in_fd, int out_fd)
{
	int	pipe_fd[2];
	int	w_status;

	if (pipe(pipe_fd) == -1)
		return (print_error_message("pipe", NULL));
	handle_child_signals();
	data->p_id = fork();
	if (data->p_id == -1)
		return (print_error_message("fork", NULL));
	if (data->p_id == 0)
		child_process_prep(data, in_fd, out_fd, pipe_fd);
	waitpid(data->p_id, &w_status, 0);
	handle_sigs_interactive();
	data->exit_codes = w_status;
	if (w_status > 255)
		data->exit_codes = w_status / 256;
	close(pipe_fd[1]);
	if (in_fd > 2)
		close(in_fd);
	if (out_fd > 2)
		close(out_fd);
	return (pipe_fd[0]);
}
