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

typedef struct s_ms_data
{
	char			**env;
	(your struct)	*commands;
	int				command_amt;
	char			*in_f;		      //Null if no < input
	char			*out_f;
	int				output_type;    //0 to std  1 >  2 >>
	bool			here_doc;
	char			*limiter;
}	t_ms_data;

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3);


#endif