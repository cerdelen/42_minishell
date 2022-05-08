/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:40:52 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:14:48 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	str_only_numerical(char *str)
{
	if (!str)
		return (0);
	while (str[0] != 0)
		if (str[0] < '0' || *str++ > '9')
			return (1);
	return (0);
}

void	numerical_argument_exception(t_ms_data *data)
{
	if (str_only_numerical(data->command[data->i].cmd_flags[1]))
	{
		print_error_message_builtin("exit",
			data->command[data->i].cmd_flags[1],
			"numeric argument required");
		free_cmd_struct_arr(data->command, data->command_amt);
		exit(255);
	}
}

int	ms_exit(t_ms_data *data)
{
	int	i;

	write(2, "exit\n", 5);
	numerical_argument_exception(data);
	if (data->command[data->i].cmd_flags[1] != NULL)
		if (data->command[data->i].cmd_flags[2] != NULL)
			print_error_message_builtin("exit", "too many arguments", NULL);
	if (data->command[data->i].cmd_flags[1] != NULL)
		if (data->command[data->i].cmd_flags[2] != NULL)
			return (1);
	if (data->command_amt > 1)
		return (1);
	if (data->command[data->i].cmd_flags[1] != NULL)
		i = ft_atoi(data->command[data->i].cmd_flags[1]);
	else
		i = -1;
	free_cmd_struct_arr(data->command, data->command_amt);
	if (i > 0)
		exit(i);
	exit(1);
}
