/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:45:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/12 23:45:57 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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

// void expand_env(char **string, char **env)
// {
// 	t_env *envv;
// 	int count;
	
// 	count = count_strings(env);
// 	envv = env_to_str(env, count);
	
// 	int i = 0;
// 	char *str = *string;
// 	char *new_str;
// 	char *variable;
// 	while(str[i])
// 	{
// 		if (str[i] == '$')
// 		{
// 			variable = get_var();
// 		}
// 		i++;
// 	}
	
// 	// print_env_struct(envv, count);
// 	// free_env_struct(envv, count);
// }

void get_indices(char *string, int *start_idx, int *end_idx)
{
	int i = 0;
	
	while(string[i])
	{
		if (string[i] == '$')
		{
			*start_idx = i + 1;
		}
		if (*start_idx)
		{
			while(string[i] != ' ')
			{
				i++;
			}
			*end_idx = i - 1;
		}
		i++;
		if (*end_idx)
			break ;		
	}
}

char *divide_string(char *string,  char *add_str, int len_s1)
{
	char **arr;
	int len_og;
	int len_big;
	int len_s2;
	int len_add_str;
	
	len_og = ft_strlen(string);
	len_s2 = len_og - len_s1 + 1;
	len_add_str = ft_strlen(add_str);
	len_big = len_og + len_add_str;
	arr = ft_calloc(3, sizeof(char *));
	arr[0] = ft_calloc(len_s1, sizeof(char));
	arr[1] = ft_calloc(len_s2 + 1, sizeof(char));
	arr[2] = NULL;
	ft_strlcpy(arr[0], string, len_s1);
	ft_strlcpy(arr[1], string + len_s1 - 1, len_s2 + 1);
	free(string);
	string = ft_calloc(len_big + 1, sizeof(char));
	ft_strlcat(string, arr[0], len_s1); 
	ft_strlcat(string, add_str, len_add_str + len_s1); 
	ft_strlcat(string, arr[1], len_add_str + len_s1 + len_s2);
	free_2d_array(arr);
	return (string);	
}

char	*trim_str(char *str, char*sub, int start_index, int finish_index)
{
	int		str_len;
	int		sub_len;
	int		i;
	int		j;
	char	*new_str;

	str_len = ft_strlen(str);
	sub_len = ft_strlen(sub) - 1;
	new_str = ft_calloc(str_len - sub_len, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < start_index || i > finish_index)
			new_str[j++] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

int main (int argc, char *argv[], char *env[])
{
	t_env *envv;
	int count;
	char *string;
	
	string = ft_strdup("something $USER else");
	count = count_strings(env);
	envv = env_to_str(env, count);
	
	int i = 0;
	int start_idx = 0;
	int end_idx = 0;
	char *variable;
	char *value;
	
	get_indices(string, &start_idx, &end_idx);
	variable = ft_calloc(start_idx + end_idx, sizeof(char));
	ft_strlcpy(variable, string + start_idx, end_idx - start_idx + 2);
	while(ft_strncmp(variable, envv[i].var, start_idx + end_idx))
		i++;
	value = ft_strdup(envv[i].val);
	string = trim_str(string, variable, start_idx - 1, end_idx);
	string = divide_string(string, value, start_idx);
	printf("%s\n", string);
	free(variable);
	free(value);
	free_env_struct(envv, count);
	free(string);
}

// echo ${USER}asdfasdfasdf
// echo $USERasdfasdfasdf
// echo '$USERasdfasdfasdf'
// echo "$USERasdfasdfasdf"
// echo "${USER}asdfasdfasdf"
// echo '${USER}asdfasdfasdf' ll