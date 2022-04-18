/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 14:45:18 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// char **rm_sp_spl_pipe(char *string)
// {
// 	char **complex_commands;
// 	int i;

// 	i = 0;
// 	complex_commands = modified_split(string, '|');
// 	while(complex_commands[i])
// 	{
// 		remove_blank_spaces(&complex_commands[i]);
// 		i++;
// 	}
// 	return (complex_commands);	
// }


// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
// string = " <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ";
// string = ft_strdup(" <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ");
// string = ft_strdup("something  something_else LANG"); '$USER' 
// string = ft_strdup(" \"$\" '\"$USER\"'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup("<<here_doc <<here_doc1 <input >output >>output2 cmd flags");
// string = ft_strdup("$?");
// string = ft_strdup(""); ////FIX ALL FUNCITONS TO BE ABLE TO WORK WITH ""
// string = ft_strdup("$ '$USER$'  '$' '\"$USER$\"''\"$USER\"' '$USER' $USER \"a $USER\" \"'$USER'\"");

int main(int argc, char *argv[], char* env[])
{
	t_env		*envv;
	int			count; 
	char		*string;
	t_full_pipe	*compl_cmds;
	int			cmd_amt;
	
	// string = ft_strdup("\"'$USER'\" '$' '\"$USER\"''\"$USER\"' '$USER' '$USER' '$USER'  '$USER' $USER \"a $USER\" \"'$USER'\"");
	// string = ft_strdup("<  input69 a<<here_doc cmd1>>  '$USER' | 'flags   <<<      '   >output1 >  $USER   output2 <inside >>hopala | <<here_doc2 cmd2 <input <here_doc4 | cmd \"some random        ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
	// string = ft_strdup("\"ec\"\"ho\" water");
	string = ft_strdup(" \"a || $USER\"  $? '$?' \"$?\" '\"$?\"' \"'$?'\" \"'$USER'\" '$USER' '\"$USER\"' | '$USER' $USER \"a $USER\" \"\"");
	// string = ft_strdup("\"a $?  \"");
	// string = ft_strdup("'$USER'");
	// string = ft_strdup(" > input");
	remove_blank_spaces(&string);
	if (errors(string))
		return (EXIT_FAILURE);
	// connect_double_angular_braces(&string);
	connect_singular_angular_braces(&string);
	// printf("%s\n", string);
	// free(string);
	// return (0);
	disconnect_angular_braces(&string);
	count = count_strings(env);
	envv = env_to_str(env, count);
	while(char_is_present('$', string))
		string = expand(string, envv, count);
	free_env_struct(envv, count);
	if (!string || string[0] == '\0') /// $asd == "" so everything segafaults	//NEED TO CHECK THIS WITH THE MAC
	{
		printf("hmm\n");
		free(string);
		return (69);
	}
	compl_cmds = fill_cmds_struct(string, &cmd_amt);
	print_cmd_struct_arr(compl_cmds, cmd_amt);
	free_cmd_struct_arr(compl_cmds, cmd_amt);
	return(0);
}


//Take care of white spaces different than space_space
//probably just convert them to space_space