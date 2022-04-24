/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:16:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/22 13:21:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

//Returns 0 if there are no errors
int	errors(char *string)
{
	if (string[0] == '|' || string[ft_strlen(string) - 1] == '|'
		|| empty_pipes(string))
		return (printf("syntax_error: near unexpected token `|'\n"), 1);
	if (!all_quotes_are_closed(string))
		return (printf("quotes_error: Quotes are not closed\n"), 2);
	if (double_pipe(string))
		return (printf("multiple_pipe_error: Only single pipes allowed\n"), 3);
	if (multiple_redirection(string, '<') || multiple_redirection(string, '>'))
		return (printf("multiple_<>_error: only >, <, >>, and << allowed\n"), 4);
	if (wrong_angular_braces(string))
		return (printf("<_>error: inappropriate use of '>' or '<'\n"), 5);
	return (0);
}
