#include "minishell.h"

static char *man_path_for_cd(char *pathname)
{
	if (strcmp)
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