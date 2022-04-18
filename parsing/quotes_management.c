/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:08:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 09:26:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//returns false (0) if the quotes are not closed - else true(1)
bool	all_quotes_are_closed(char *str)
{
	bool	d_quotes_open;
	bool	s_quotes_open;
	int		idx;

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

void reset_quotes()
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
	// else if (status == S_OPEN_FIRST || status == D_OPEN_SECOND)
	// 	return (NONE_OPEN);
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

// int maint()
// {
// 	char *string = " '\"$USER\"' $USER \"$US";
// 	int i = 0;
// 	int status = 0;
// 	while (string[i])
// 	{
// 		if (string[i] == '\'')
// 		{
// 			status = single_quotes_open(status);
// 			// printf("Code: %d\n", status);
// 		}
// 		else if (string[i] == '\"')
// 		{
// 			status = double_quotes_open(status);
// 			// printf("Code: %d\n", status);
// 		}

// 		if (string[i] == '$')
// 		{
// 			if (status == NONE_OPEN || status == S_OPEN_ONLY)
// 				printf("No quelse if (status == D_OPEN_ONLY)otes. Print: $\n");

// 				printf("Double quotes. Expand: $\n");
// 			else if (status == S_OPEN_SECOND)
// 				printf("Double, single. Expand: $\n");
// 			else if (status == D_OPEN_SECOND)
// 				printf("Single, double. Expand: $\n");
// 		}
// 		i++;
// 	}
// }
