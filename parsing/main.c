/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/15 19:18:33 by kmilchev         ###   ########.fr       */
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

// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
// string = " <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ";
// string = ft_strdup(" <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ");
// string = ft_strdup("something  something_else LANG"); '$USER' 
// string = ft_strdup("\"'$USER'\" '$' '\"$USER\"''\"$USER\"' '$USER' '$USER' '$USER'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup(" \"$\" '\"$USER\"'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup(" $ '\"$USER\"'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup("$ '$USER$' '$' '\"$USER$\"''\"$USER\"' '$USER' '$USER' '$USER'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup("$?");

int main(int argc, char *argv[], char* env[])
{
	t_env		*envv;
	int			count; 
	char		*string;
	char		**arr;
	int			command_amt;
	t_full_pipe	*compl_cmds;
	
	// string = ft_strdup("<<here_doc cmd1>>  $USER | 'flags   <<<      '   >output1 >  $USER   output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random        ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
	string = ft_strdup("<<here_doc <<here_doc1 <input >output >>output2 cmd flags");
	if (errors(string))
		return (EXIT_FAILURE);
	count = count_strings(env);
	envv = env_to_str(env, count);
	while(char_is_present('$', string))
		string = expand(string, envv, count);
	printf("%s\n", string);
	arr = modified_split(string, '|');
	
	command_amt = count_chars(string, '|') + 1;
	compl_cmds = malloc(sizeof(t_full_pipe) * command_amt);
	int i = 0;
	while(i < command_amt)
	{
		compl_cmds[i] = fill_cmd(arr[i]);
		print_cmd_struct(compl_cmds[i]);
		printf("______________\n");
		i++;
	}
	// printf("\n%s\n", arr[0]);
	// print_2d_array(arr);
	free(string);
}



// 1. Expand $
// 2. split at white_space
// 3. 
// 	else if "<<"
// 	else if ">>"
// 	else if "<"
// 	else if ">"
// 	else if 

//Take care of white spaces different than space_space
//probably just convert them to space_space