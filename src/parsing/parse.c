/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:58:03 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 19:46:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parse(char **string, t_ms_data	*data)
{
	int		count;
	t_env	*envv;

	data->command_amt = 0;
	replace_white_spaces(string);
	remove_blank_spaces(string);
	if (errors(*string))
	{
		free(*string);
		return (EXIT_FAILURE);
	}
	connect_singular_angular_braces(string);
	disconnect_angular_braces(string);
	count = count_strings(data->env);
	envv = env_to_str(data->env, count);
	while (char_is_present('$', *string))
		*string = expand(*string, envv, count, data);
	free_env_struct(envv, count);
	data->command = fill_cmds_struct(*string, data);
	return (EXIT_SUCCESS);
}
