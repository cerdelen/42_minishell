/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:16:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/16 17:38:22 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int errors(char *string)
{
	if (!all_quotes_are_closed(string))
	{
		// printf("quotes_error: Quotes are not closed\n");
		free(string);
		return (printf("quotes_error: Quotes are not closed\n"), 1);
	}
	if (double_pipe(string))
	{
		free(string);
		printf("double_pipe_error: Only single pipes allowed\n");
		return (2);
	}
	if (multiple_redirection(string, '<') || multiple_redirection(string, '>'))
	{
		free(string);
		printf("multiple angular brace: only >, <, >>, and << allowed\n");
		return (3);
	}
	return (0);
}


// Returns true(1) if there's double pipes outside of quotes, else false (0)
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
