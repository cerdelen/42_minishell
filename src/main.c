/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 12:14:23 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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


int	main(int argc, char *argv[], char *env[])
{
	t_ms_data			data;
	char				*line;

	data.exit_codes = 0;
	data.env = env_copy(env);
	handle_sigs_interactive();
	if (argc != 1 && argv)
		return (printf("KISCER_SHELL does not take arguments\n"), 0);
	while (1)
	{
		line = readline(WHATEVS);
		if (!line)
		{
			write(2, "exit\n", 5);
			break ;
		}
		if (line[0] == 0)
			continue ;
		if (ft_strlen(line) > 0)
			add_history(line);
		if (parse(&line, &data))
			continue ;
		command_exec_loop(&data);
		free_cmd_struct_arr(data.command, data.command_amt);
	}
	return (0);
}