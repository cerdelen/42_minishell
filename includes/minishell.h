#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdbool.h>
# include "libft.h"
# include <stdio.h>

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# define WHATEVS "\e[0;35mKISCER_SHELL \e[31mv1.0\e[0m $ "

typedef struct s_complex_command t_cmd;
typedef struct s_ms_data
{
	char				**env;
	t_cmd				*command;
	int					command_amt;
	pid_t				p_id;
	int					exit_codes;
	int					i;
	struct sigaction	sa_int;
}	t_ms_data;

# include "signals.h"
# include "parsing.h"
# include "builtins.h"
# include "get_next_line.h"
# include "commands_and_exec.h"

#endif
