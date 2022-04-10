/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:23:49 by cerdelen          #+#    #+#             */
/*   Updated: 2022/04/10 11:03:20 by cerdelen         ###   ########.fr       */
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

void	cd_error_message(char *pathname)
{
	char	*error_msg;
	
	error_msg = strerror(errno);
	write(STDERR_FILENO, "cd: ", 4);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, pathname, ft_strlen(pathname));
	write(STDERR_FILENO, "\n", 1);
}

int	command_cd(char *pathname)
{
	char	*path_after_mod;
	int		check;

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
			cd_error_message(pathname);
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
