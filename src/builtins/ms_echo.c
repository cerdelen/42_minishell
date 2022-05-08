/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:00:30 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 14:01:58 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	flag_is_present(char **cmd, int i)
{
	int		j;
	bool	new_line;

	if (cmd[1] == NULL)
		return (printf("\n"), 0);
	j = 1;
	new_line = false;
	if (cmd[i][0] == '-' && cmd[i][1] == 'n')
	{
		while (cmd[i][j])
		{
			if (cmd[i][j] != 'n')
			{
				new_line = true;
				break ;
			}
			j++;
		}
		(i)++;
	}
	else
		new_line = true;
	return (new_line);
}

bool	every_char_is(char c, char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != c)
			return (false);
		i++;
	}
	return (true);
}

int	ms_echo(char **cmd_flags)
{
	int		i;
	bool	new_line;
	bool	no_skip;

	i = 1;
	new_line = flag_is_present(cmd_flags, i);
	no_skip = true;
	while (cmd_flags[i])
	{
		if (cmd_flags[i][0] == '-'
			&& every_char_is('n', cmd_flags[i]) && no_skip)
		{
			i++;
			continue ;
		}
		no_skip = false;
		printf("%s", cmd_flags[i]);
		if (cmd_flags[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
	return (0);
}
