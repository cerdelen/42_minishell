/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:45:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/12 12:47:35 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void print_struct(t_env *envv, int i)
{
	int j;
	j = 0;
	while (j < i)
	{
		printf("Variable: %s, ", envv[j].var);
		printf("Value: %s\n", envv[j].val);
		j++;
	}
}

void free_env_struct(t_env *envv, int i)
{
	int j;
	j = 0;
	while (j < i)
	{
		free(envv[j].var);
		free(envv[j].val);
		j++;
	}
	free(envv);
}


t_env *env_to_str(char **env, int j)
{
	int i = 0;
	char **var_val;
	t_env *envv;
	envv = malloc(sizeof(t_env) * j);
	while(i < j)
	{
		var_val = ft_split(env[i], '=');
		envv[i].var = ft_strdup(var_val[0]);
		envv[i].val = ft_strdup(var_val[1]);
		(i)++;
		free_2d_array(var_val);
	}
	return (envv);
}

int count_strings(char **env)
{
	int i;
	
	i = 0;
	while (env[i])
		i++;
	return (i);
}
void expand_env(char **string, char **env)
{
	t_env *envv;
	int count;
	
	count = count_strings(env);
	envv = env_to_str(env, count);
	// print_struct(envv, count);
	free_env_struct(envv, count);
}

int main (int argc, char *argv[], char *env[])
{
	char *string = "hey&USER";
	expand_env(&string, env);
}

//// echo ${USER}asdfasdfasdf
//// echo $USERasdfasdfasdf