/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:08:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/24 09:28:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

//returns false (0) if the quotes are not closed - else true(1)
bool	all_quotes_are_closed(char *str)
{
	t_data	d;

	d.d_quotes_open = false;
	d.s_quotes_open = false;
	d.idx = -1;
	while (str[++d.idx])
	{
		if (str[d.idx] == '\'' && !d.d_quotes_open)
		{
			if (d.s_quotes_open)
				d.s_quotes_open = false;
			else
				d.s_quotes_open = true;
		}
		else if (str[d.idx] == '\"' && !d.s_quotes_open)
		{
			if (d.d_quotes_open)
				d.d_quotes_open = false;
			else
				d.d_quotes_open = true;
		}
	}
	if (!d.d_quotes_open && !d.s_quotes_open)
		return (true);
	return (false);
}

//sets the static variables inside the functions to their default value: false
void	reset_quotes(void)
{
	if (quotes_are_closed('\'') == false)
		quotes_are_closed('\'');
	if (quotes_are_closed('\"') == false)
		quotes_are_closed('\"');
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

int	single_quotes_open(int status)
{
	if (status == NONE_OPEN)
		return (S_OPEN_ONLY);
	else if (status == D_OPEN_ONLY)
		return (S_OPEN_SECOND);
	else if (status == S_OPEN_SECOND || status == D_OPEN_FIRST)
		return (D_OPEN_ONLY);
	else
		return (NONE_OPEN);
}

int	double_quotes_open(int status)
{
	if (status == NONE_OPEN)
		return (D_OPEN_ONLY);
	else if (status == D_OPEN_ONLY || status == D_OPEN_FIRST
		|| status == S_OPEN_SECOND)
		return (NONE_OPEN);
	else if (status == D_OPEN_SECOND || status == S_OPEN_FIRST)
		return (S_OPEN_FIRST);
	else
		return (D_OPEN_SECOND);
}
