/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 14:31:25 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
			write(2, "exit\n", 5);
		if (!line)
			break ;
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
