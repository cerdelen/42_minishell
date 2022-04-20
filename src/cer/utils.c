#include "../../includes/minishell.h"

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*out;

	temp = ft_strjoin(s1, s2);
	out = ft_strjoin(temp, s3);
	free(temp);
	return (out);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	char	*out;

	out = ft_strjoin(s1, s2);
	free(s1);
	return (out);
}

void	print_error_message(char *pathname, char *command)
{
	char	*error_msg;

	error_msg = strerror(errno);
	if (command != NULL)
		write(STDERR_FILENO, command, ft_strlen(command));
	else
		write(STDERR_FILENO, "kiscer_ms", 9);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, pathname, ft_strlen(pathname));
	write(STDERR_FILENO, "\n", 1);
}