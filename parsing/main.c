/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:34:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/17 21:01:44 by kmilchev         ###   ########.fr       */
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


// int main()
// {
// 	printf("Status code: %d\n", wrong_angular_braces(" > >file | >file2> | file< | > | > correct | < also_correct"));
// 	// printf("Status code: %d\n", wrong_angular_braces("< "));
// }

// int main()
// {
// 	char **arr;
// 	char *word;
// 	printf("'$USER'\n");
// 	arr = ft_split("'oneword'", '\'');
// 	word = ft_strtrim("'1''2''3'", "'");
// 	print_2d_array(arr);
// 	printf(word);
// }
// string = ft_strdup("<<here_doc cmd1   '                    flags'   >output1 >    output2 <inside >>hopala | <<here_doc2 cmd2 < input> <here_doc4 | cmd \"some random ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");
// string = " <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ";
// string = ft_strdup(" <<here_doc2  ' c  a  r '     cmd2 < input> <here_doc4 ");
// string = ft_strdup("something  something_else LANG"); '$USER' 
// string = ft_strdup("\"'$USER'\" '$' '\"$USER\"''\"$USER\"' '$USER' '$USER' '$USER'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup(" \"$\" '\"$USER\"'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup(" $ '\"$USER\"'  '$USER' $USER \"a $USER\" \"'$USER'\"");
// string = ft_strdup("$?");
// string = ft_strdup("<<here_doc <<here_doc1 <input >output >>output2 cmd flags");
// string = ft_strdup("a<<here_doc cmd1>>  '$USER' | 'flags   <<<      '   >output1 >  $USER   output2 <inside >>hopala | <<here_doc2 cmd2 <input> <here_doc4 | cmd \"some random        ass shit\" | peace >output | something \"<<there\" '<<it' \"'<<nope'\" >>yes is enough");


//$? needs NOT be expanded 
int main(int argc, char *argv[], char* env[])
{
	t_env		*envv;
	int			count; 
	char		*string;
	char		**arr;
	t_full_pipe	*compl_cmds;
	
	// string = ft_strdup(""); ////FIX ALL FUNCITONS TO BE ABLE TO WORK WITH ""
	string = ft_strdup("$ '$USER$'  '$' '\"$USER$\"''\"$USER\"' '$USER' $USER \"a $USER\" \"'$USER'\"");
	remove_blank_spaces(&string);
	if (errors(string))
		return (EXIT_FAILURE);
	connect_double_angular_braces(&string);
	connect_singular_angular_braces(&string);
	count = count_strings(env);
	envv = env_to_str(env, count);
	while(char_is_present('$', string))
		string = expand(string, envv, count);
	if (!string || string[0] == '\0') /// $asd == "" so everything segafaults	//NEED TO CHECK THIS WITH THE MAC
	{
		printf("hmm\n");
		free(string);
		free_env_struct(envv, count);
		return (69);
	}
	arr = modified_split(string, '|');
	
	int			command_amt;
	int i = 0;
	command_amt = count_chars(string, '|') + 1;
	compl_cmds = malloc(sizeof(t_full_pipe) * command_amt);
	while(i < command_amt)
	{
		compl_cmds[i] = fill_cmd(arr[i]);
		i++;
	}
	print_cmd_struct_arr(compl_cmds, command_amt);
	print_2d_array(arr);
	free_cmd_struct_arr(compl_cmds, command_amt);
	free_env_struct(envv, count);
	free_2d_array(arr);
	free(string);
	return(0);
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