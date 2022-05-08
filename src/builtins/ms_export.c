/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:59:29 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 13:50:27 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	validate(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && ft_isdigit(str[0])) || !ft_isalnum_underscore(str[i]))
		{
			print_error_message_export("export: `", str,
				"': not a valid identifier");
			return (1);
		}
		i++;
	}
	return (0);
}

char	**add_var(char *var, char *env[])
{
	int		i;
	char	**new_arr;

	i = 0;
	while (env[i])
		i++;
	new_arr = malloc(sizeof(char *) * (i + 3));
	i = 0;
	while (env[i])
	{
		new_arr[i] = ft_strdup(env[i]);
		i++;
	}
	new_arr[i] = ft_strdup(var);
	new_arr[i + 1] = NULL;
	free_2d_array(env);
	return (new_arr);
}

bool	norm(t_ms_data *data, int i, char **var_val)
{
	int		j;
	bool	added;

	j = -1;
	added = false;
	while (data->env[++j])
	{
		if (ft_strncmp(var_val[0], data->env[j], ft_strlen(var_val[0])) == 0)
		{
			free(data->env[j]);
			data->env[j] = ft_strdup(data->command[data->i].cmd_flags[i]);
			added = true;
			break ;
		}
	}
	return (added);
}

void	export_util(t_ms_data *data, int i, char **var_val, bool added)
{
	while (data->command[data->i].cmd_flags[++i])
	{
		if (data->command[data->i].cmd_flags[i][0] == '='
			|| ft_isdigit(data->command[data->i].cmd_flags[i][0]))
		{
			print_error_message_export("export: `",
				data->command[data->i].cmd_flags[i],
				"': not a valid identifier");
			continue ;
		}
		if (!ft_strchr(data->command[data->i].cmd_flags[i], '='))
			continue ;
		var_val = ft_split(data->command[data->i].cmd_flags[i], '=');
		if (var_val[0] == NULL)
			continue ;
		if (validate(var_val[0]))
		{
			free_2d_array(var_val);
			continue ;
		}
		added = norm(data, i, var_val);
		if (!added)
			data->env = add_var(data->command[data->i].cmd_flags[i], data->env);
		free_2d_array(var_val);
	}
}

int	ms_export(t_ms_data *data)
{
	char	**var_val;
	bool	added;
	int		i;

	i = 0;
	if (data->command[data->i].cmd_flags[1] == NULL)
	{
		while (data->env[i])
		{
			printf("declare -x %s\n", data->env[i]);
			i++;
		}
		return (0);
	}
	export_util(data, 0, var_val, added);
	return (0);
}
