/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 16:40:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
void print_2d_array_1(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void free_2d_array_1(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int main(void)
{
	t_r_s vars;
	char *string;
	char **complex_commands;
	int n_cmds;
	t_full_pipe *list_cmds;
	
	string = "cmd1 'flags' >output1 >    output2 | cmd2 < input | cmd \"some random ass shit\" | peace";
	if (!quotes_are_closed(string))
	{
		printf("quotes_error: Quotes are not closed\n");
		return (1);
	}
	if (double_pipe(string))
	{
		printf("double_pipe_error: Only single pipes allowed\n");
		return (2);
	}
	complex_commands = modified_split(string, '|');
	n_cmds = count_chars(string, '|') + 1;
	printf("Number of commands: %d\n", n_cmds);

	list_cmds = malloc(sizeof(t_full_pipe) * n_cmds);
	// int i = 0;
	// while (complex_commands[i])
	// {
	// 	list_cmds[i].reddir_in = get_single_redirection(complex_commands[i], '<');
	// 	list_cmds[i].reddir_out = get_single_redirection(complex_commands[i], '>');
	// }

	// printf("\n\n%s\n\n\n", list_cmds[2].cmd);

	
	print_2d_array_1(complex_commands);
	free_2d_array_1(complex_commands);
}