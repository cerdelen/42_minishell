/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:23:49 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/06 16:36:33 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getcwd(void)
{
	char	*completepath;
	int		i;

	i = 10;
	completepath = malloc(i * sizeof(char));
	getcwd(completepath, i);
	while (errno == ERANGE)
	{
		errno = 0;
		i = i + 10;
		free(completepath);
		completepath = malloc(i * sizeof(char));
		getcwd(completepath, i);
	}
	return (completepath);
}

char	*man_path_for_cd(char *pathname)
{
	char	*cur_wd;
	int		ret;
	char	*out;

	if (ft_strncmp("/", pathname, 1) == 0)
		return (pathname);
	cur_wd = ft_getcwd();
	out = ft_tripple_strjoin(cur_wd, "/", pathname);
	free(cur_wd);
	return (out);
}

int	ms_cd(char *pathname, char *home, t_ms_data *data)
{
	char	*path_after_mod;
	int		check;

	if (data->command_amt > 1)
		return (-1);
	if (pathname == NULL)
		pathname = home;
	if (ft_strlen(pathname) == 0)
		return (0);
	path_after_mod = man_path_for_cd(pathname);
	if (path_after_mod)
	{
		check = chdir(path_after_mod);
		if (check != 0)
		{
			print_error_message("cd", pathname);
			if (ft_strncmp("/", pathname, 1) != 0)
				free(path_after_mod);
			return (1);
		}
	}
	if (ft_strncmp("/", pathname, 1) != 0)
		free(path_after_mod);
	return (0);
}
