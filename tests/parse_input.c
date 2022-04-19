/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/14 10:09:41 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int count_chars(char *str, char c);

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
		if (str[idx] == c)
			count++;
		idx++;
	}
	return (count);
}




// int main ()
// {
// 	printf("Quotes are closed: %d, should be 1\n", all_quotes_are_closed("\'\'\"\""));
// 	printf("Quotes are closed: %d, should be 1\n", all_quotes_are_closed("\'\"\'"));
// 	printf("Quotes are closed: %d, should be 1\n", all_quotes_are_closed("\"\'\""));
// 	printf("Quotes are closed: %d, should be 0\n", all_quotes_are_closed("\'\""));
// 	printf("Quotes are closed: %d, should be 0\n", all_quotes_are_closed("\'\"\'\"\'"));
// 	printf("Quotes are closed: %d, should be 0\n", all_quotes_are_closed("\"\'\"\'\"\'\""));
// 	return (0);
// }