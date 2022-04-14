/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:08:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/14 10:22:27 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//returns false (0) if the quotes are not closed - else true(1)
bool all_quotes_are_closed(char *str)
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
bool	quotes_are_closed(char c)
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
