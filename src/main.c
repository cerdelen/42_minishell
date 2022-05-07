/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/07 20:24:05 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_redisplay();
	}
}

void handle_parent_signals(t_ms_data *data)
{
	data->sa_int.sa_handler = &sigint_handler;
	sigaction(SIGINT, &(data->sa_int), NULL);
	signal(SIGQUIT, SIG_IGN);
}

void child_signal_handler(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	else if (sig == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
}


void handle_child_signals(t_ms_data *data)
{
	data->sa_int.sa_handler = &child_signal_handler;
	sigaction(SIGINT, &(data->sa_int), NULL);
	signal(SIGQUIT, child_signal_handler);
	// data->sa_quit.sa_handler = SIG_DFL;
	// data->sa_quit.sa_handler = &handle_signals_children;
	// sigaction(SIGQUIT, &(data->sa_quit), NULL);
}

// static void	sigint_handler(int signal)
// {
// 	if (signal)
// 	{
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		rl_redisplay();
// 	}
// }

// Register SIGINT handler and ignore SIGQUIT for parent process
// void	handle_parent_signals(void)
// {
// 	signal(SIGINT, sigint_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }

// SIGINT and SIGQUIT handler for child process
// static void	child_signal_handler(int signal)
// {
// 	if (signal == SIGQUIT)
// 		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
// 	else if (signal == SIGINT)
// 		ft_putchar_fd('\n', STDERR_FILENO);
// }

// Register SIGINT and SIGQUIT handler for child process
// void	handle_child_signals(void)
// {
// 	signal(SIGINT, child_signal_handler);
// 	signal(SIGQUIT, child_signal_handler);
// }
