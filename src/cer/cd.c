/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:23:49 by cerdelen          #+#    #+#             */
/*   Updated: 2022/04/09 14:42:05 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	command_cd(char *pathname)
{
	char	*path_after_mod;
	int		check;
	char	*error_msg;

	if (pathname == NULL)
		return (0);
	if (ft_strlen(pathname) == 0)
		return (0);
	path_after_mod = man_path_for_cd(pathname);
	if (path_after_mod)
	{
		check = chdir(path_after_mod);
		if (check != 0)
		{
			error_msg = strerror(errno);
			printf("cd: %s: %s\n", error_msg, pathname);
			if (ft_strncmp("/", pathname, 1) != 0)
				free(path_after_mod);
			return (1);
		}
	}
	if (ft_strncmp("/", pathname, 1) != 0)
		free(path_after_mod);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*test;

	test = ft_getcwd();
	printf("pwd before call = %s\n", test);
	free(test);
	if (argc == 1)
		command_cd(NULL);
	if (argc == 1)
		command_cd("");
	else
		command_cd(argv[1]);
	test = ft_getcwd();
	printf("pwd after call = %s\n", test);
	free(test);
}
