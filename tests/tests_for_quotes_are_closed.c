/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_for_quotes_are_closed.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/08 18:44:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool quotes_are_closed(char c)
{
	static bool d_quotes_open = false;
	static bool s_quotes_open = false;

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

int main ()
{
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\'\'\"\""));
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\'\"\'"));
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\"\'\""));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\'\""));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\'\"\'\"\'"));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\"\'\"\'\"\'\""));
	return (0);
}