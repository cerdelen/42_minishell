/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:04:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 14:23:14 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_doc_child_proccess(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	if (fd[1] < 0)
		exit(-1);
	while (1)
	{
		line = readline(">");
		if (!line)
		{
			printf("Readline Error\n");
			exit(-1);
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}

int	ms_true_heredoc(char *limiter)
{
	int	fd[2];
	int	w_status;
	int	id;

	if (pipe(fd) == -1)
		return (print_error_message("pipe", NULL));
	id = fork();
	if (id == -1)
		return (print_error_message("fork", NULL));
	if (id == 0)
		here_doc_child_proccess(limiter, fd);
	wait(&w_status);
	if (w_status < 0)
		return (print_error_message("here_doc_child",
				"process return w_status"));
	close(fd[1]);
	return (fd[0]);
}

void	ms_fake_heredoc(char *limiter)
{
	char	*line;

	printf("this is start of fake_heredoc\n");
	while (1)
	{
		line = readline(">");
		if (!line)
		{
			printf("Readline Error\n");
			break ;
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

int	heredoc_prep(char *limiter, bool last, t_ms_data *data)
{
	int	fd;

	if (last == false)
		ms_fake_heredoc(limiter);
	fd = ms_true_heredoc(limiter);
	data->exit_codes = 0;
	return (fd);
}
