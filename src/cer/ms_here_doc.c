#include "../../includes/minishell.h"

// int	heredoc_prep(char *limiter, bool fake)
// {
// 	char	*line;

// 	while (1)
// 	//fake heredocs einfach nur solange newline bis line == limiter
// 	//real heredoc hiddenfile erstellen und nach command file löschenda höchstens
// 	//1 input pro command
// 	{
// 		line = readline("kiscer>");
// 		if (line == limiter)
// 			break ;
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }



// int	heredoc_hidden_storage()
// {
// 	open_and_check_access("./hidden_heredoc_file", READS_AND_WRITES, false, true);
// }

int	ms_true_heredoc(char *limiter)
{
	char	*line;
	int		fd;

	fd = open_and_check_access("hidden_heredoc_file", READS_AND_WRITES, false, true);
	if (fd < 0)
		return (-1);
	while(1)
	{
		line = readline(">");
		if (!line)
		{
			printf("Readline Error\n");
			break ;
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	return (fd);
}

void	ms_fake_heredoc(char *limiter)
{
	char	*line;

	printf("this is start of fake_heredoc\n");
	while(1)
	{
		line = readline(">");
		if (!line)
		{
			printf("Readline Error\n");
			break ;
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}



int	heredoc_prep(char *limiter, bool last)
{
	
	//fake heredocs einfach nur solange newline bis line == limiter
	//real heredoc hiddenfile erstellen und nach command file löschenda höchstens
	//1 input pro command
	int	fd;

	if (last == true)
		fd = ms_true_heredoc(limiter);
	else
		ms_fake_heredoc(limiter);
	return (fd);
}
