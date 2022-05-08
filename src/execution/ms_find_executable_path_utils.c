/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_executable_path_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:04:50 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:04:51 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path_from_env(char **env)
{
	int		i;
	char	*out;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			out = ft_strjoin(env[i], "");
			return (out);
		}
		i++;
	}
	return (NULL);
}

char	*free__path_arrays(char *path, char **arr)
{
	char	*out;
	int		i;

	i = 0;
	out = NULL;
	if (path != NULL)
		out = ft_strjoin(path, "");
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (out);
}
