/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/24 17:20:16 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_ms_data	data;
	char		*line;

	if (argc != 1 && argv)
		return (printf("KISCER_SHELL does not take arguments\n"), 0);
	while (1)
	{
		line = readline("KISCER_SHELL >");
		if (!line)
		{
			printf("EXITING\n");
			break ;
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		if (parse(&line, env, &data.command, &data.command_amt))
		{
			printf("ERROR");
			return (EXIT_FAILURE);
		}
		printf("this is the command in main functions %s\n", data.command[0].cmd_flags[0]);
		data.env = env;
		printf("data.exitcodes in main = %d\n", *data.exit_codes);
		command_exec_loop(&data);
		/* print_cmd_struct_arr(data.command, data.command_amt); */
		free_cmd_struct_arr(data.command, data.command_amt);
		printf("Everything worked! yeay\n");
	}
	return (0);
}
