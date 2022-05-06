/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:56:45 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/06 16:58:14 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_env(char **cmd_flags, char **env)
{
	if (cmd_flags[1])
	{
		print_error_message_builtin("env",
			"the command does not accept arguments", NULL);
		return (1);
	}
	else
	{
		print_2d_array(env);
		return (0);
	}
}
