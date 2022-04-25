/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:58:03 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/25 14:28:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parse(char **string, char *env[], t_cmd **cmds, int *cmd_amt)
{
	int		count;
	t_env	*envv;

	*cmd_amt = 0;
	replace_white_spaces(string);
	remove_blank_spaces(string);
	if (errors(*string))
	{
		free(*string);
		return (EXIT_FAILURE);
	}
	connect_singular_angular_braces(string);
	disconnect_angular_braces(string);
	count = count_strings(env);
	envv = env_to_str(env, count);
	while (char_is_present('$', *string))
		*string = expand(*string, envv, count);
	free_env_struct(envv, count);
	// if ((*string)[0] == '\0')
	// {
	// 	free(*string);
	// 	return (EXIT_FAILURE);
	// }
	*cmds = fill_cmds_struct(*string, cmd_amt);
	return (EXIT_SUCCESS);
}
