/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:45:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 09:35:58 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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
		envv[i].val = ft_strdup(var_val[1]);
		i++;
		free_2d_array(var_val);
	}
	return (envv);
}

bool	char_available(char *string, int i, int status)
{
	if (status == S_OPEN_ONLY || status == D_OPEN_SECOND)
		return (false);
	else if (status == NONE_OPEN
		&& (string[i + 1] == '\0'
			|| string[i + 1] == '\"'
			|| string[i + 1] == '\''))
		return (false);
	else if (status == NONE_OPEN && string[i + 1] && string[i + 1] == ' ' )
		return (false);
	else if ((status == NONE_OPEN) && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == S_OPEN_SECOND && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == '\"')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == ' ')
		return (false);
	else
		return (true);
}

bool	char_is_present(char c, char *string)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (string[i])
	{
		if (string[i] == '\'')
			status = single_quotes_open(status);
		else if (string[i] == '\"')
			status = double_quotes_open(status);
		else if (string[i] == c)
		{	
			if (char_available(string, i, status))
				return (true);
		}
		i++;
	}
	return (false);
}

int	get_indices(char *string, int *start_idx, int *end_idx)
{
	int	i;
	int status;
	
	status = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '\'')
			status = single_quotes_open(status);
		else if (string[i] == '\"')
			status = double_quotes_open(status);

		if (string[i] == '$') ///SPECIAL CASE FOR $? NEEDED
		{
			// if (status == S_OPEN_ONLY || status == D_OPEN_SECOND)
			// 	{}//MAYBE I DON"T NEED THIS CONDITION ANY MORE
			if (string[i + 1] && string[i + 1] == '?')
				{}
			else if (string[i + 1] && string[i + 1] == ' ')
				{}
			else if (status == NONE_OPEN || status == D_OPEN_ONLY || status == S_OPEN_SECOND)
			{
				if (string[i + 1] && string[i + 1] != '\"') //"$"
					*start_idx = i + 1;
			}
		}
		if (*start_idx)
		{
			while (string[i] && string[i] != ' ' && string[i] != '\'' && string[i] != '\"')
				i++;
			*end_idx = i - 1;
		}
		i++;
		if (*end_idx)
			break ;
	}
	if (*start_idx != 0)
		return (0);
	return (1);
}

char	*reassamble_string(char *string, char *add_str, int len_s1)
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

char	*remove_part_string(char *str, char*sub, int start_index, int finish_index)
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

/* First argument is a string, second is array of my struct.
If the string is found in the array, it is returned. Else \0 is returned. */
char	*find_match(char *string, t_env *arr, int len, int arr_size)
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
char	*expand(char *string, t_env *envv, int count)
{
	int		i;
	int		start_idx;
	int		end_idx;
	char	*variable;
	char	*value;
	
	i = 0;
	start_idx = 0;
	end_idx = 0;
	if (get_indices(string, &start_idx, &end_idx))
		return (string);
	variable = ft_calloc(end_idx - start_idx + 2, sizeof(char));
	ft_strlcpy(variable, string + start_idx, end_idx - start_idx + 2);
	value = find_match(variable, envv, start_idx + end_idx, count);
	string = remove_part_string(string, variable, start_idx - 1, end_idx);
	string = reassamble_string(string, value, start_idx);
	free(variable);
	free(value);
	return (string);
}

// echo ${USER}asdfasdfasdf   -- IGNORE curly braces
// echo "${USER}asdfasdfasdf" -- IGNORE curly braces
// echo '${USER}asdfasdfasdf' -- IGNORE curly braces
// echo $USERasdfasdfasdf
// echo '$USERasdfasdfasdf'
// echo "$USERasdfasdfasdf"
// echo "'${USER}'"
