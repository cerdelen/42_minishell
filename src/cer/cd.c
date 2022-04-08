#include "minishell.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char *ft_getcwd(void)
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

char	*ft_erase_l_folder_of_path(char *cur_wd)
{
	char	*temp;
	char	*out;

	temp = ft_strrchr(cur_wd, '\\');
	if (temp)
		temp[1] = 0;
	out = ft_strlcpy(cur_wd, ft_strlen(cur_wd));
	return (out);
}

static char *man_path_for_cd(char *pathname)
{
	char	*cur_wd;
	int		ret;
	char	*out;

	cur_wd = ft_getcwd();
	if (ft_strncmp("..", pathname, ft_strlen(pathname)) == 0)
		return (ft_erase_l_folder_of_path(cur_wd));
	else if (ft_strncmp(".", pathname, ft_strlen(pathname)) == 0)
		return ();
	else
		out = ft_strjoin(cur_wd, pathname);
		free(cur_wd);
		return (ft_strjoin(cur_wd, pathname));

}

int	command_cd(char *pathname)
{
	
	if (!chdir(pathname))
	{
		perror(pathname);
		return (1);
	}
	return (0);
}