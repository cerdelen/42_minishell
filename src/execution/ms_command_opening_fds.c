/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_opening_fds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:05:26 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:05:27 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	prep_input_fd_util(t_ms_data *data, int i, int counter)
{
	char	*tmp;
	int		in_fd;

	tmp = ft_strtrim(data->command[i].input[counter], " <");
	if (data->command[i].input[counter][1] == ' ')
		in_fd = open_and_check_access(tmp, READS_ONLY, false, false);
	else
		in_fd = heredoc_prep(tmp, true, data);
	return (in_fd);
}

int	prep_input_fd(t_ms_data *data, int i, int in_fd)
{
	int		counter;
	char	*tmp;

	counter = 0;
	if (in_fd != STDIN_FILENO && in_fd > 0)
		close(in_fd);
	while (data->command[i].input[counter + 1])
	{
		tmp = ft_strtrim(data->command[i].input[counter], " <");
		if (data->command[i].input[counter][1] == ' ')
			in_fd = access(tmp, R_OK);
		else
			heredoc_prep(tmp, false, data);
		if (in_fd < 0)
		{
			print_error_message(tmp, NULL);
			free(tmp);
			return (in_fd);
		}
		free(tmp);
		counter++;
	}
	return (prep_input_fd_util(data, i, counter));
}

int	prep_output_fd_util(t_ms_data *data, int i, int counter)
{
	int		out_fd;
	char	*tmp;

	tmp = ft_strtrim(data->command[i].output[counter], " >");
	if (data->command[i].output[counter][1] == ' ')
		out_fd = open_and_check_access(tmp, WRITES_ONLY, false, true);
	else
		out_fd = open_and_check_access(tmp, WRITES_ONLY, true, true);
	if (out_fd < 0)
		print_error_message(tmp, NULL);
	free(tmp);
	return (out_fd);
}

int	prep_output_fd(t_ms_data *data, int i, int out_fd)
{
	int		counter;
	char	*tmp;

	counter = 0;
	while (data->command[i].output[counter + 1])
	{
		tmp = ft_strtrim(data->command[i].output[counter], " >");
		if (data->command[i].output[counter][1] == ' ')
			out_fd = open_and_check_access(tmp, WRITES_ONLY, false, true);
		else
			out_fd = open_and_check_access(tmp, WRITES_ONLY, true, true);
		if (out_fd < 0)
			print_error_message(tmp, NULL);
		free(tmp);
		if (out_fd < 0)
			return (out_fd);
		close(out_fd);
		counter++;
	}
	return (prep_output_fd_util(data, i, counter));
}
