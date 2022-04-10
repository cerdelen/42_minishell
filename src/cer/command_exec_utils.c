/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:21:06 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/10 11:48:16 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_descriptors(int n_fds, ...)
{
	va_list	fds;
	int		i;

	va_start(fds, n_fds);
	i = 0;
	while (i < n_fds)
	{
		close(va_arg(fds, int));
		i++;
	}
}

char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	ft_validity_check(int n, char *error_message)
{
	if (n == -1)
	{
		perror(error_message);
		return (0);
	}
	return (1);
}

void	check_number_of_arguments(int n)
{
	if (n < 5)
	{
		ft_printf("Error! Too few arguments...\n");
		exit(1);
	}
}

char	**get_paths(char *env[])
{
	int		idx;
	char	*str;
	char	**out;

	idx = 0;
	while (!(ft_strnstr(env[idx], "PATH=", 5)))
		idx++;
	str = ft_strtrim(env[idx], "PATH=");
	out = ft_split(str, ':');
	free(str);
	idx = 0;
	while (out[idx])
	{
		str = ft_strjoin(out[idx], "/");
		free(out[idx]);
		out[idx] = str;
		idx++;
	}
	return (out);
}
