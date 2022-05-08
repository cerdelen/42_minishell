/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:23:14 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:31:00 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	execute_exeption_command(t_ms_data *data, int in_fd, int out_fd,
	int *pipe_fd )
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

int	non_fork_exception(t_ms_data *data)
{
	char	*cmd;

	cmd = data->command[data->i].cmd_flags[0];
	if (ft_strncmp(cmd, "exit", 6) == 0)
		return (ms_exit(data));
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
	int	w_status;
	int	check;

	check = non_fork_exception(data);
	if (check > -1)
		data->exit_codes = check;
	if (check > -1)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (print_error_message("pipe", NULL));
	data->p_id = fork();
	if (data->p_id == -1)
		return (print_error_message("fork", NULL));
	if (data->p_id == 0)
		exit(execute_exeption_command(data, in_fd, out_fd, pipe_fd));
	waitpid(data->p_id, &w_status, 0);
	data->exit_codes = w_status;
	if (w_status > 255)
		data->exit_codes = w_status / 256;
	close(pipe_fd[1]);
	close(in_fd);
	if (out_fd != STDOUT_FILENO)
		close(out_fd);
	return (pipe_fd[0]);
}

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
