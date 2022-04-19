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
	char	**reddir_in; //NULL
	char	**reddir_out; //NULL
	char	**reddir_out_app; //NULL
	char	**here_doc; //NULL
	char	**cmd_arr; //NULL
} t_full_pipe;

typedef struct s_ms_data
{
	char				**env;
	t_full_pipe			*command;
	int					command_amt;
	pid_t				p_id;
	int					*exit_codes;
}	t_ms_data;

#endif
