#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft.h"
# include "commands_and_exec.h"
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
	pid_t			p_id;
}	t_ms_data;

#endif