/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:20:31 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:20:58 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cleanup_command(int cleanup_case, int in_fd, int out_fd)
{
	int	fd[2];

	if (cleanup_case == 1 && in_fd > 2)
		close(in_fd);
	if (cleanup_case == 2)
	{
		if (in_fd > 2)
			close(in_fd);
		if (out_fd > 2)
			close(out_fd);
	}
	pipe(fd);
	close(fd[1]);
	return (fd[0]);
}

char	*ms_find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	return (env[i] + 5);
}
