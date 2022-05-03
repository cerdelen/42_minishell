/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/25 14:00:52 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *place_holder()
{
	char *out = malloc(5 * sizeof(char));
	out[0] = 'e';
	out[1] = 'x';
	out[2] = 'i';
	out[3] = 't';
	out[4] = '\0';
	return (out);
}

int	main(int argc, char *argv[], char *env[])
{
	t_ms_data	data;
	char		*line;

	if (argc != 1 && argv)
		return (printf("KISCER_SHELL does not take arguments\n"), 0);
	while (1)
	{
		line = place_holder();
		printf("%s'\n", line);
		if (!line)
		{
			printf("EXITING\n");
			break ;
		}
		// if (ft_strlen(line) > 0)
		// 	add_history(line);
		if (parse(&line, env, &data.command, &data.command_amt))
		{
			printf("ERROR");
			return (EXIT_FAILURE);
		}
		data.env = env;
		command_exec_loop(&data);
		/* print_cmd_struct_arr(data.command, data.command_amt); */
		free_cmd_struct_arr(data.command, data.command_amt);
	}
	return (0);
}
