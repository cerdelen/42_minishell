/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/24 10:52:07 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_ms_data	data;
	char		*line;
	if (argc != 1 && argv)
		return (printf("KISCER_SHELL does not take arguments\n"), 0);
	printf("HELLO\n");
	while(1)
	{
		line = readline("KISCER_SHELL >");
		printf("HELLO2\n");
		if (!line)
		{
			printf("EXITING\n");
			break ;
		}
		printf("HELLO3\n");
		if (ft_strlen(line) > 0)
			add_history(line);
		printf("HELLO4\n");
		if(parse(&line, env, &data.command, &data.command_amt))
		{
			printf("ERROR");
			return (EXIT_FAILURE);
		}
		printf("HELLO\n");
		printf("this is the command in main functions %s\n", data.command[0].cmd_flags[0]);
		command_exec_loop(&data);
		/* print_cmd_struct_arr(data.command, data.command_amt); */
		free_cmd_struct_arr(data.command, data.command_amt);
	}
	return (0);
}
