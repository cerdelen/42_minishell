/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:44:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 14:47:58 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

//counts how many instances of a character are present in a string
//if the char is within any quotes, it is not counted
//returns -1 if either of the arguments is not present
int	count_chars(char *str, char c)
{
	int	idx;
	int	count;

	if (!str || !c)
		return (-1);
	idx = 0;
	count = 0;
	while (str[idx])
	{
		if (quotes_are_closed(str[idx]) && str[idx] == c)
			count++;
		idx++;
	}
	reset_quotes();
	return (count);
}

//Receives a double array. Counts the elements and returns the number.
int	count_strings(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**env_copy(char **env)
{
	char	**env_cp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	env_cp = ft_calloc(i + 3, sizeof(char *));
	i = 0;
	while (env[i])
	{
		env_cp[i] = ft_strdup(env[i]);
		i++;
	}
	env_cp[i] = NULL;
	return (env_cp);
}
