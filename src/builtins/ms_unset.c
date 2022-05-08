/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:18:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 14:01:17 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalnum_underscore(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else if (c == 95)
		return (1);
	else
		return (0);
}

int	validate_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && ft_isdigit(str[0])) || !ft_isalnum_underscore(str[i]))
		{
			printf("ms_unset: '%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

void	update_array(char *var, char *env[])
{
	int	j;

	j = 0;
	while (env[j])
	{
		if (ft_strncmp(var, env[j], ft_strlen(var)) == 0)
		{
			free(env[j]);
			while (env[j + 1])
			{	
				env[j] = ft_strdup(env[j + 1]);
				j++;
			}
			env[j] = NULL;
			break ;
		}
		j++;
	}
}

int	ms_unset(t_ms_data *data)
{
	char	*var;
	int		i;
	int		err_res;

	i = 1;
	while (data->command[data->i].cmd_flags[i])
	{
		var = data->command[data->i].cmd_flags[i];
		err_res = validate_name(var);
		if (err_res)
		{
			i++;
			continue ;
		}
		update_array(var, data->env);
		i++;
	}
	return (0);
}
