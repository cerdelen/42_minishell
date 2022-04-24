/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:44:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/24 09:28:30 by kmilchev         ###   ########.fr       */
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