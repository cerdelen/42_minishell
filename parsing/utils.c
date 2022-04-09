/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:44:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 16:08:00 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"


void print_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void free_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

//counts how many instances of a character are present in a string
//returns -1 if either of the arguments is not present
int count_chars(char *str, char c)
{
	int idx;
	int count;
	
	if (!str || !c)
		return (-1);
	idx = 0;
	count = 0;
	while (str[idx])
	{
		if (quotes_are_closed_no_loop(str[idx]) && str[idx] == c)
			count++;
		idx++;
	}
	return (count);
}
