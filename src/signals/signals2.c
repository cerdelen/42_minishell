/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:38:30 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 20:05:45 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	here_doc_child(int signal)
{
	if (signal == SIGINT)
		exit(1);
}

void	handle_here_doc_signals_parent(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	handle_here_doc_signals_child(void)
{
	signal(SIGINT, here_doc_child);
	signal(SIGQUIT, SIG_IGN);
}
