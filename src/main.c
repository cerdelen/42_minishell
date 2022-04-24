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
	while(1)
	{
		line = readline("KISCER_SHELL >");
		if (!line)
		{
			printf("EXITING\n");
			break ;
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		if(parse(&line, env, &data.command, &data.command_amt))
		{
			printf("ERROR");
			return (EXIT_FAILURE);
		}
		print_cmd_struct_arr(data.command, data.command_amt);
		free_cmd_struct_arr(data.command, data.command_amt);
	}
	return (0);
}
