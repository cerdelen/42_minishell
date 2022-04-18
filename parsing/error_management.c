/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:16:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 12:50:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//Returns 0 if there are no errors
int	errors(char *string)
{
	if (!all_quotes_are_closed(string))
	{
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
		printf("multiple_angular_brace: only >, <, >>, and << allowed\n");
		return (3);
	}
	if (wrong_angular_braces(string))
	{
		free(string);
		return (printf("<_>error: inappropriate use of '>' or '<'\n"), 1);
	}
	return (0);
}

// Returns true(1) if there's double pipes outside of quotes, else false (0)
bool	double_pipe(char *string)
{
	int		i;
	char	curr_char;
	char	next_char;

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
	return (false);
}

//checks for >>> or <<<. 
//returns true (1) if present, else false(0);
bool	multiple_redirection(char *string, char c)
{
	int		i;
	char	curr_char;
	char	next_char;
	char	third_char;

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
	return (false);
}

//returns -1 for error
int	check_angular_braces(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (quotes_are_closed(string[i]))
		{	
			if ((string[i] == '>' || string[i] == '<') && string[i + 1] == '\0')
				return (-1);
			else if ((string[i] == '>' || string[i] == '<')
				&& string[i + 2] && (string[i + 2] == '>'
					|| string[i + 2] == '<'))
				return (-1);
		}
		i++;
	}
	return (0);
}

//return true(1) for error
bool	wrong_angular_braces(char *string)
{
	char	**arr;
	int		i;
	int		status;

	status = 0;
	i = 0;
	arr = modified_split(string, '|');
	while (arr[i])
	{
		remove_blank_spaces(&arr[i]);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		status = check_angular_braces(arr[i]);
		if (status)
		{
			free_2d_array(arr);
			return (true);
		}
		i++;
	}
	free_2d_array(arr);
	return (false);
}
