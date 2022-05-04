/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:59:29 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/04 17:03:08 by kmilchev         ###   ########.fr       */
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
			printf("export: '%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

void	no_arguments(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		// write(1, "declare -x ", 12);
		// write(1, env[i], ft_strlen(env[i]));
		// write(1, "\n", 2);		
		i++;
	}
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

void	export_util(t_ms_data *data, int i, int j)
{
	char	**var_val;
	bool	added;

	while (data->command[data->i].cmd_flags[++i])
	{
		var_val = ft_split(data->command[data->i].cmd_flags[i], '=');
		j = -1;
		added = false;
		if (validate(var_val[0]))
		{
			i++;
			continue ;
		}
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
		if (!added)
		{
			data->env = add_var(data->command[data->i].cmd_flags[i], data->env);
		}
		free_2d_array(var_val);
	}
}

int	ms_export(t_ms_data *data) //char **cmd_flags, char *env[]
{
	int		j;
	char	**var_val;

	// if (data->command[data->i]->cmd_flags[0] == NULL)
	if (data->command[data->i].cmd_flags[1] == NULL)
	{
		no_arguments(data->env);
		return (0);
	}
	export_util(data, -1, -1);
	return (0);
}

// int	main(int argc, char *argv[], char *env[])
// {
// 	char	**envv;
// 	char	**cmd_flags;
// 	t_ms_data d;
// 	d.env = env_copy(env);
// 	cmd_flags = malloc(21 * sizeof(char *));
// 	// cmd_flags[0] = ft_strdup("635d=22");
// 	// cmd_flags[1] = ft_strdup("USER=grzegorzbrzeczyszczykiewicz");
// 	// cmd_flags[2] = ft_strdup("LOGNAME=wyrewolwerowanyrewolwerowiec");
// 	// cmd_flags[3] = ft_strdup("NEW_VARIABLE1=");
// 	// cmd_flags[4] = ft_strdup("City=chrzyszczyrzegorzycepowiatlekodoly");
// 	cmd_flags[0] = NULL;
// 	d.cm
// 	// print_2d_array(envv);
// 	ms_export(d);
// 	// print_2d_array(envv);
// 	free_2d_array(envv);
// 	free_2d_array(cmd_flags);
// }
