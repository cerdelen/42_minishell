/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:45:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 18:07:41 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*env_to_str(char **env, int j)
{
	int		i;
	char	**var_val;
	t_env	*envv;

	i = 0;
	envv = malloc(sizeof(t_env) * j);
	while (i < j)
	{
		var_val = ft_split(env[i], '=');
		envv[i].var = ft_strdup(var_val[0]);
		if (var_val[1] == NULL)
			envv[i].val = ft_strdup("");
		else
			envv[i].val = ft_strdup(var_val[1]);
		i++;
		free_2d_array(var_val);
	}
	return (envv);
}

static char	*reassamble_string(char *string, char *add_str, int len_s1)
{
	char	**arr;
	int		len_og;
	int		len_big;
	int		len_s2;
	int		len_add_str;

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

static char	*rm_part_str(char *str, char*sub, int start_idx, int finish_idx)
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
		if (i < start_idx || i > finish_idx)
			new_str[j++] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

/* First argument is a string, second is array of my struct.
If the string is found in the array, it is returned. Else \0 is returned. */
static char	*find_match(char *string, t_env *arr, int len, int arr_size)
{
	int	i;

	i = 0;
	while (ft_strncmp(string, arr[i].var, len))
	{	
		i++;
		if (i == arr_size)
		{
			string = ft_strdup("\0");
			break ;
		}
	}
	if (string[0] != '\0')
	{
		string = ft_strdup(arr[i].val);
	}
	return (string);
}

//Find $, retrieve the value for the env variable, replace it in the string
char	*expand(char *string, t_env *envv, int count, t_ms_data *data)
{
	int		start_idx;
	int		end_idx;
	char	*variable;
	char	*value;

	start_idx = 0;
	end_idx = 0;
	if (get_indices(string, &start_idx, &end_idx))
		return (string);
	variable = ft_calloc(end_idx - start_idx + 2, sizeof(char));
	ft_strlcpy(variable, string + start_idx, end_idx - start_idx + 2);
	if (ft_strncmp(variable, "?", 1) == 0)
		value = ft_itoa(data->exit_codes);
	else
		value = find_match(variable, envv, start_idx + end_idx, count);
	string = rm_part_str(string, variable, start_idx - 1, end_idx);
	string = reassamble_string(string, value, start_idx);
	free(value);
	free(variable);
	return (string);
}
