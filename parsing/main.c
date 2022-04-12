/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/11 22:14:41 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int main(void)
{
	// t_r_s vars;
	char *string;
	char *str_sp;
	char **complex_commands;
	// int n_cmds;
	// t_full_pipe *list_cmds;
	
	// string = ft_strdup("<<here_doc cmd1   'flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
	// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
	string = ft_strdup(" <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ");
	// string = " <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ";
	if (errors(string))
		return (EXIT_FAILURE);
	
	complex_commands = modified_split(string, '|');
	// n_cmds = count_chars(string, '|') + 1;
	// list_cmds = malloc(sizeof(t_full_pipe) * n_cmds + 1);
	printf("Before clean up: %s\n", string);
	str_sp = remove_blank_spaces2(string);
	printf("After clean up: %s\n", str_sp);
	// print_struct_array(list_cmds, n_cmds);
	// free_struct_array(list_cmds, n_cmds);
	free_2d_array(complex_commands);
	free(str_sp);
	free(string);
}


// 1. remove remove_blank_spaces
// 2. Expand $
// 3. split at pipe
// 4. 
// 	if "$"
// 	else if "<<"
// 	else if ">>"
// 	else if "<"
// 	else if ">"
// 	else if 


//OLD STUFF
/*
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
		list_cmds[i].reddir_in = get_single_redirections(&complex_commands[i], '<', &vars);
		list_cmds[i].reddir_out = get_single_redirections(&complex_commands[i], '>', &vars);
		i++;
	}
	i = 0;
*/