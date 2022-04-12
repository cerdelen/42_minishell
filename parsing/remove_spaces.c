/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:58:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/11 22:43:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"
#include "../includes/minishell.h"

void remove_blank_spaces(char **string)
{
	char *new;
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (quotes_are_closed_no_loop(temp[i]) && temp[i] == ' ' && temp[i + 1] == ' ')
		{
			i++;
			continue ;
		}
		new[j++] = temp[i];
		i++;
	}
	// printf("\nFUNCTION: %s\n", new);
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

char *remove_blank_spaces2(char *string)
{
	char *new;
	char *temp;
	int i;
	int j;
	i = 0;
	j = 0;
	new = ft_strdup(string);
	while(string[i])
	{
		if (quotes_are_closed_no_loop(string[i]) && string[i] == ' ' && string[i + 1] == ' ')
		{
			i++;
			continue ;
		}
		new[j++] = string[i];
		i++;
	}
	new[j] = '\0';
	temp = ft_strtrim(new, " ");
	// printf("TEMP: %s\n", temp);
	string = ft_strdup(temp);
	// printf("STRING: %s\n", temp);
	free(new);
	free(temp);
	return (string);
}