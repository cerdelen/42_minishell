/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:38:30 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 19:38:57 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	another_one(int signal)
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
	signal(SIGINT, another_one);
	signal(SIGQUIT, SIG_IGN);
}
