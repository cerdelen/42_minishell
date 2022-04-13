/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/13 20:38:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char **rm_sp_spl_pipe(char *string)
{
	char **complex_commands;
	int i;

	i = 0;
	complex_commands = modified_split(string, '|');
	while(complex_commands[i])
	{
		remove_blank_spaces(&complex_commands[i]);
		i++;
	}
	return (complex_commands);	
}

// string = ft_strdup("<<here_doc cmd1  | 'flags         '   >output1 >  $USER   output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random        ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
// string = " <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ";
//string = ft_strdup(" <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ");

int main(int argc, char *argv[], char* env[])
{
	t_env	*envv;
	int		count; 
	char	*string;
	
	string = ft_strdup("something '$USER' something_else $LANG");
	// if (errors(string))
		// return (EXIT_FAILURE);
	count = count_strings(env);
	envv = env_to_str(env, count);
	string = expand(string, envv, count);
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