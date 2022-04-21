#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "commands_and_exec.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_complex_command
{
	char	**input;
	char	**output;
	char	**cmd_flags;
}	t_cmd;

typedef struct s_ms_data
{
	char				**env;
	t_cmd				*command;
	int					command_amt;
	pid_t				p_id;
	int					*exit_codes;
}	t_ms_data;

#endif
