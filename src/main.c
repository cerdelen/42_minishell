/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:46:07 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 16:30:27 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	main_loop(t_ms_data *data)
{
	char	*line;
	
	while (1)
	{
		line = readline(PROMPT);
		if (!line)
		{
			write(2, "exit\n", 5);
			free_2d_array(data->env);
		}
		if (!line)
			break ;
		if (line[0] == 0)
			continue ;
		if (ft_strlen(line) > 0)
			add_history(line);
		if (parse(&line, data))
			continue ;
		command_exec_loop(data);
		free_cmd_struct_arr(data->command, data->command_amt);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_ms_data			data;

	handle_sigs_interactive();
	if (argc != 1 && argv)
	{
		ft_putstr_fd("KISCER_SHELL does not take arguments\n", 2);
		return (0);
	}
	data.exit_codes = 0;
	data.env = env_copy(env);
	main_loop(&data);
	return (0);
}
