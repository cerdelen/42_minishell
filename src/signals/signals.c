/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:31:08 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 19:38:54 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sigint_handler(int signal)
{
	if (signal)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_redisplay();
	}
}

void	handle_sigs_interactive(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	child_signal_handler(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	else if (signal == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
}

void	handle_child_signals(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}
