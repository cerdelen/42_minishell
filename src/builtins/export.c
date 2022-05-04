/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:59:29 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/04 15:50:13 by kmilchev         ###   ########.fr       */
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

char	**export_util(char **cmd_flags, char *env[], int i, int j)
{
	char	**var_val;
	bool	added;

	while (cmd_flags[++i])
	{
		var_val = ft_split(cmd_flags[i], '=');
		j = -1;
		added = false;
		if (validate(var_val[0]))
		{
			i++;
			continue ;
		}
		while (env[++j])
		{
			if (ft_strncmp(var_val[0], env[j], ft_strlen(var_val[0])) == 0)
			{
				free(env[j]);
				env[j] = ft_strdup(cmd_flags[i]);
				added = true;
				break ;
			}
		}
		if (!added)
			env = add_var(cmd_flags[i], env);
		free_2d_array(var_val);
	}
	return (env);
}

char	**ms_export(char **cmd_flags, char *env[])
{
	int		i;
	int		j;
	char	**var_val;
	bool	added;

	i = 0;
	added = false;
	if (cmd_flags[0] == NULL)
	{
		no_arguments(env);
		return (env);
	}
	env = export_util(cmd_flags, env, -1, -1);
	return (env);
}

int	main(int argc, char *argv[], char *env[])
{
	char	**envv;
	char	**cmd_flags;

	envv = env_copy(env);
	cmd_flags = malloc(21 * sizeof(char *));
	cmd_flags[0] = ft_strdup("635d=22");
	cmd_flags[1] = ft_strdup("USER=grzegorzbrzeczyszczykiewicz");
	cmd_flags[2] = ft_strdup("LOGNAME=wyrewolwerowanyrewolwerowiec");
	cmd_flags[3] = ft_strdup("NEW_VARIABLE1=");
	cmd_flags[4] = ft_strdup("City=chrzyszczyrzegorzycepowiatlekodoly");
	cmd_flags[5] = NULL;
	// print_2d_array(envv);
	envv = export(cmd_flags, envv);
	print_2d_array(envv);
	free_2d_array(envv);
	free_2d_array(cmd_flags);
}
