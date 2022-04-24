#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdbool.h>
# include "libft.h"
# include "parsing.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_ms_data
{
	char				**env;
	t_cmd				*command;
	int					command_amt;
	pid_t				p_id;
	int					*exit_codes;
	int					i;
}	t_ms_data;

# include "get_next_line.h"
# include "commands_and_exec.h"

#endif
