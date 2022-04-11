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
	t_ms_commands		*commands;
	int			command_amt;
	pid_t			p_id;
}	t_ms_data;

#endif
