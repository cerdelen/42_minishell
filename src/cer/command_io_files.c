#include "../../includes/minishell.h"

int	command_prep_in(t_ms_data *data, char **redirr_in)
{
	int	i;

	if (redirr_in)
	while (redirr_in[i] != NULL)
	{
		
	}
	int	in;

	in = open(data->in_file, O_RDONLY);
	if (!ft_validity_check(in, data->in_file))
		return (-1);
	dup2(in, STDIN_FILENO);
	return (in);
}