/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:16:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/14 10:09:41 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int errors(char *string)
{
	if (!all_quotes_are_closed(string))
	{
		// printf("quotes_error: Quotes are not closed\n");
		return (printf("quotes_error: Quotes are not closed\n"), 1);
	}
	if (double_pipe(string))
	{
		printf("double_pipe_error: Only single pipes allowed\n");
		return (2);
	}
	if (multiple_redirection(string, '<') || multiple_redirection(string, '>'))
	{
		printf("multiple angular brace: only >, <, >>, and << allowed\n");
		return (3);
	}
	return (0);
}
