#include "../../includes/minishell.h"

int	ms_pwd(void)
{
	char	*completepath;
	int		i;

	printf("unseres pwd\n");
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
	printf("%s\n", completepath);
	free(completepath);
	return (0);
}