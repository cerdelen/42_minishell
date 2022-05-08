/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:04:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 19:35:39 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_doc_child_proccess_true(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	if (fd[1] < 0)
		return ;
	while (1)
	{
		line = readline(">");
		if (!line)
			exit(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
}

void	here_doc_child_proccess_fake(char *limiter)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			if (line)
				free(line);
			exit (0);
			break ;
		}
		free(line);
	}
}

int	here_doc_forking(char *limiter, t_ms_data *data, bool last)
{
	int	fd[2];
	int	w_status;

	if (pipe(fd) == -1)
		return (print_error_message("pipe", NULL));
	handle_here_doc_signals_parent();
	data->p_id = fork();
	if (data->p_id == -1)
		return (print_error_message("fork", NULL));
	if (data->p_id == 0)
	{
		handle_here_doc_signals_child();
		if (last == true)
			here_doc_child_proccess_true(limiter, fd);
		if (last == false)
			here_doc_child_proccess_fake(limiter);
	}
	waitpid(data->p_id, &w_status, 0);
	handle_sigs_interactive();
	data->exit_codes = w_status;
	close(fd[1]);
	if (last == false)
		close(fd[0]);
	return (fd[0]);
}

int	heredoc_prep(char *limiter, bool last, t_ms_data *data)
{
	int	fd;

	fd = here_doc_forking(limiter, data, last);
	data->exit_codes = 0;
	return (fd);
}
