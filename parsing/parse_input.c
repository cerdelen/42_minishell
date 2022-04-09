/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 16:39:42 by kmilchev         ###   ########.fr       */
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
	quotes_are_closed_no_loop(string[i]);
	return (false);
}


// int main(void)
// {
// 	t_r_s vars;
// 	char *redirection;
// 	char *string = "grep '|< ' <      input3.txt whatever";

// 	redirection = find_single_redirection(string, '<', &vars);
// 	printf("%s\n", redirection);
// 	printf("Start index: %d\nFinish index: %d\n", vars.start_index, vars.finish_index);
// 	printf("New string: %s\n", trim_string(string, redirection, &vars));
// 	return (0);
// }

