/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/26 12:08:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t pid = 0;
int	main(int argc, char *argv[], char *env[])
{
	t_ms_data			data;
	char				*line;
	// struct sigaction	sa;

	// sa.sa_handler = &handle_signals;
	// sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);

	data.env = env_copy(env);
	if (argc != 1 && argv)
		return (printf("KISCER_SHELL does not take arguments\n"), 0);
	while(1)
	{
		line = readline(WHATEVS);
		if (!line)
		{
			printf(" EXITING\n");
			break ;
		}
		if (line[0] == 0)
			continue;
		// printf("env pointer == %p\n", data.env);
		if (ft_strlen(line) > 0)
			add_history(line);
		if (parse(&line, data.env, &data.command, &data.command_amt))
		{
			printf("ERROR\n");
			continue ;
		}
		// print_cmd_struct_arr(data.command, data.command_amt);
		command_exec_loop(&data);
		free_cmd_struct_arr(data.command, data.command_amt);
	}
	return (0);
}
