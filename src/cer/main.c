#include "minishell.h"

void	signal_fork(void)
{
	int fd[2];
	int	id;

	id = pipe(fd);
	if (id != 0)
	{
		perror(NULL);
		return (1);
	}
	id = fork();
	if (id == -1)
	{
		perror(NULL);
		return (2);
	}
	if (id == 0)
		return (0);
	while (1)
	{
		get_next_line();
		
	}
}

int	main(void)
{
	signal_fork();
}