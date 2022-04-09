#include "minishell.h"

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*out;

	temp = ft_strjoin(s1, s2);
	out = ft_strjoin(temp, s3);
	free(temp);
	return (out);
}

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

static char *man_path_for_cd(char *pathname)
{
	char	*cur_wd;
	int		ret;
	char	*out;

	if (ft_strncmp("/",pathname, 1) == 0)
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

	path_after_mod = man_path_for_cd(pathname);
	// printf("string for chdir = %s\n", path_after_mod);
	if (path_after_mod)
	{
		check = chdir(path_after_mod);
		if (check != 0)
		{
			error_msg = strerror(errno);
			printf("cd: %s: %s\n", error_msg, pathname);
			if (ft_strncmp("/",pathname, 1) != 0)
				free(path_after_mod);
			return (1);
		}
	}
	if (ft_strncmp("/",pathname, 1) != 0)
		free(path_after_mod);
	return (0);
}

int main(int argc, char **argv)
{
	char *XD;

	XD = ft_getcwd();
	printf("pwd before call = %s\n", XD);
	free(XD);
	command_cd(argv[1]);
	XD = ft_getcwd();
	printf("pwd after call = %s\n", XD);
	free(XD);
}