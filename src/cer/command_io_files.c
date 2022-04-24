#include "../../includes/minishell.h"

int	make_input_file(char *name)
{
	
}

int	command_prep_in(t_ms_data *data, char **redirr_in)
{
	int		i;
	int		ret;
	char	*line;

	if (redirr_in)
	{
		while (redirr_in[i] != NULL)
		{
			open()
			line = get_next_line()
			i++;
		}
	}
	int	in;

	in = open(data->in_file, O_RDONLY);
	if (!ft_validity_check(in, data->in_file))
		return (-1);
	dup2(in, STDIN_FILENO);
	return (in);
}