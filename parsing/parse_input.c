/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/10 15:44:07 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//returns false (0) if the quotes are not closed - else true(1)
bool quotes_are_closed(char *str)
{
	bool d_quotes_open;
	bool s_quotes_open;
	int idx;
	
	d_quotes_open = false;
	s_quotes_open = false;
	idx = 0;

	while (str[idx])
	{
		if (str[idx] == '\'' && !d_quotes_open)
		{
			if (s_quotes_open)
				s_quotes_open = false;
			else
				s_quotes_open = true;
		}
		else if (str[idx] == '\"' && !s_quotes_open)
		{
			if (d_quotes_open)
				d_quotes_open = false;
			else
				d_quotes_open = true;
		}
		idx++;
		
	}
	if (!d_quotes_open && !s_quotes_open)
		return (true);
	return (false);
}

//Gets called in a loop
//returns false (0) if the quotes are not closed - else true(1)
bool	quotes_are_closed_no_loop(char c)
{
	static bool	d_quotes_open = false;
	static bool	s_quotes_open = false;

	if (c == '\'' && !d_quotes_open)
	{
		if (s_quotes_open)
			s_quotes_open = false;
		else
			s_quotes_open = true;
	}
	else if (c == '\"' && !s_quotes_open)
	{
		if (d_quotes_open)
			d_quotes_open = false;
		else
			d_quotes_open = true;
	}
	if (!d_quotes_open && !s_quotes_open)
		return (true);
	return (false);
}

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
		if (!quotes_are_closed_no_loop(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && curr_char == '|')
			return (true);
		i++;
	}
	// quotes_are_closed_no_loop(string[i]);
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
		if (!quotes_are_closed_no_loop(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && next_char == third_char && curr_char == c)
			return (true);
		i++;
	}
	// quotes_are_closed_no_loop(string[i]);
	return (false);
}