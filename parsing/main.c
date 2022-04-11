/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/11 09:44:48 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int errors(char *string)
{
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
	if (multiple_redirection(string, '<') || multiple_redirection(string, '>'))
	{
		printf("multiple angular brace: only >, <, >>, and << allowed\n");
		return (3);
	}
	return (0);
}

int main(void)
{
	t_r_s vars;
	char *string;
	char **complex_commands;
	int n_cmds;
	t_full_pipe *list_cmds;
	
	string = "<<here_doc cmd1   'flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough";
	// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
	if (errors(string))
		return (EXIT_FAILURE);
	
	complex_commands = modified_split(string, '|');
	n_cmds = count_chars(string, '|') + 1;
	list_cmds = malloc(sizeof(t_full_pipe) * n_cmds + 1);
	
	int i = 0;
	while (complex_commands[i])
	{
		list_cmds[i].reddir_out_app = get_double_redirections(&complex_commands[i], '>', &vars);
		list_cmds[i].here_doc = get_double_redirections(&complex_commands[i], '<', &vars);
		i++;
	}
	i = 0;
	while (complex_commands[i])
	{
		list_cmds[i].reddir_out = get_single_redirections(&complex_commands[i], '>', &vars);
		list_cmds[i].reddir_in = get_single_redirections(&complex_commands[i], '<', &vars);
		i++;
	}
	i = 0;
	
	// while (complex_commands[i])
	// {
		printf("BEFOR STRING:%sX\n", string);
		// remove_blank_spaces(&string);
		printf("AFTER ______:%sX\n", string);
		// list_cmds[i].cmd = complex_commands[i];
		// i++;

	// }
	print_struct_array(list_cmds, n_cmds);
	free_struct_array(list_cmds, n_cmds);
	free_2d_array(complex_commands);
	// free(string);
}

// void change_str(char **string)
// {
// 	char *buf;
// 	// buf = ft_strdup(*string);
// 	free(*string);
// 	buf = "asdfasdf";
// 	*string = ft_strdup(buf);
// 	printf("From function: %s\n", *string);
// 	// free(buf);
// }
// int main (void)
// {
// 	char **arr;
	
// 	arr = ft_split("Some words here", ' ');
// 	print_2d_array(arr);
// 	change_str(&arr[0]);
// 	printf("String: %s\n", arr[0]);	
// 	printf("String: %s\n", arr[1]);	
// 	printf("String: %s\n", arr[2]);	
// 	free_2d_array(arr);
// }