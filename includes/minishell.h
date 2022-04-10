#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_ms_data
{
	char			**env;
	// (your struct)	*commands;
	int				command_amt;
	char			*in_file;		      //Null if no < input
	char			*out_file;
	int				output_type;    //0 to std  1 >  2 >>
	bool			here_doc;
	char			*limiter;
}	t_ms_data;

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3);
void	close_descriptors(int n_fds, ...);
char	**ft_free(char **array);
int		ft_validity_check(int n, char *error_message);
void	check_number_of_arguments(int n);
char	**get_paths(char *env[]);
int	command_exec(t_ms_data *data);

#endif