#include "../../includes/minishell.h"

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_command_struct(t_cmd *command_struct)
{
	free_string_array(command_struct->input);
	free_string_array(command_struct->output);
	free_string_array(command_struct->cmd_flags);
}

void	ms_exit(t_ms_data *data)
{
	free_string_array(data->env);
	free_command_struct(data->command);
	free(data->exit_codes);
	free(data->i);
}
