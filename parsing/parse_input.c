/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/15 16:23:22 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//Returns true(1) if there's double pipes outside of quotes, else false (0)
bool double_pipe(char *string)
{
	int i;
	char curr_char;
	char next_char;
	i = 0;
	while (string[i + 1])
	{
		curr_char = string[i];
		next_char = string[i + 1];
		if (!quotes_are_closed(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && curr_char == '|')
			return (true);
		i++;
	}
	// quotes_are_closed(string[i]);
	return (false);
}

//checks for >>> or <<<. 
//returns true (1) if present, else false(0);
bool multiple_redirection(char *string, char c)
{
	int i;
	char curr_char;
	char next_char;
	char third_char;
	i = 0;
	while (string[i + 2])
	{
		curr_char = string[i];
		next_char = string[i + 1];
		third_char = string[i + 2];
		if (!quotes_are_closed(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && next_char == third_char && curr_char == c)
			return (true);
		i++;
	}
	// quotes_are_closed(string[i]);
	return (false);
}

t_full_pipe fill_command(char **arr)
{
	int i;

	i = 0;
	while ((arr[i]))
	{
		if (ft_strncmp(">>", arr[i], 2) == 0 )
			{}
		else if ("<<")
			{}
		else if ("<")
			{}
		else if (">")
			{}
	}
}