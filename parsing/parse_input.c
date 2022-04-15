/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/15 19:21:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// Returns true(1) if there's double pipes outside of quotes, else false (0)
bool double_pipe(char *string)
{
	int i;
	char curr_char;
	char next_char;
	i = 0;
	while (string[i + 1])
	{
		curr_char = string[i];
		next_char = string[i + 1];
		if (!quotes_are_closed(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && curr_char == '|')
			return (true);
		i++;
	}
	// quotes_are_closed(string[i]);
	return (false);
}

//checks for >>> or <<<. 
//returns true (1) if present, else false(0);
bool multiple_redirection(char *string, char c)
{
	int i;
	char curr_char;
	char next_char;
	char third_char;
	i = 0;
	while (string[i + 2])
	{
		curr_char = string[i];
		next_char = string[i + 1];
		third_char = string[i + 2];
		if (!quotes_are_closed(curr_char))
		{
			i++;
			continue ;
		}
		if (curr_char == next_char && next_char == third_char && curr_char == c)
			return (true);
		i++;
	}
	// quotes_are_closed(string[i]);
	return (false);
}

void init_el_am(char **elements, t_n_el *el_amount)
{
	int i;
	
	ft_bzero(el_amount, sizeof(t_n_el));
	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0 )
			el_amount->n_red_out_app++;
		else if (ft_strncmp("<<", elements[i], 2) == 0)
			el_amount->n_here_doc++;
		else if ('<' == elements[i][0])
			el_amount->n_red_in++;
		else if ('>' == elements[i][0])
			el_amount->n_red_out++;
		else 
			el_amount->n_cmd_flags++;
		i++;
	}
}

void init_cmd_struct(t_full_pipe *cmd, t_n_el *el_amount, char **arr)
{
	init_el_am(arr, el_amount);
	cmd->cmd_flags = malloc(sizeof(char *) * el_amount->n_cmd_flags + 1);
	cmd->here_doc = malloc(sizeof(char *) * el_amount->n_here_doc + 1);
	cmd->reddir_in = malloc(sizeof(char *) * el_amount->n_red_in + 1);
	cmd->reddir_out = malloc(sizeof(char *) * el_amount->n_red_out + 1);
	cmd->reddir_out_app = malloc(sizeof(char *) * el_amount->n_red_out_app + 1);
	
	cmd->cmd_flags[el_amount->n_cmd_flags] = NULL;
	cmd->here_doc[el_amount->n_here_doc] = NULL;
	cmd->reddir_in[el_amount->n_red_in] = NULL;
	cmd->reddir_out[el_amount->n_red_out] = NULL;
	cmd->reddir_out_app[el_amount->n_red_out_app] = NULL;
}

t_full_pipe fill_cmd(char *string)
{
	int i;
	char **elements;
	t_full_pipe cmd;
	t_n_el el_amount;
	
	elements = modified_split(string, ' ');
	init_cmd_struct(&cmd, &el_amount, elements);
	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0 )
			cmd.reddir_out_app[el_amount.idx_red_out_app++] = ft_strdup(elements[i] + 2); //ft_strdup(string[i + 2])
		else if (ft_strncmp("<<", elements[i], 2) == 0)
			cmd.here_doc[el_amount.idx_here_doc++] = ft_strdup(elements[i] + 2);
		else if ('<' == elements[i][0])
			cmd.reddir_in[el_amount.idx_red_in++] = ft_strdup(elements[i] + 1);
		else if ('>' == elements[i][0])
			cmd.reddir_out[el_amount.idx_red_out++] = ft_strdup(elements[i] + 1);
		else 
			cmd.cmd_flags[el_amount.idx_cmd_flags++] = ft_strdup(elements[i]);
		i++;
	}
	return (cmd);
}

// int main()
// {
// 	t_n_el el_amount;
// 	char *string = "<<here_doc >>sth  $USER $?";
// 	char **arr = modified_split(string, ' ');
	
// 	init_el_am(arr, &el_amount);
// 	printf("%d\n", el_amount.n_cmd_flags);
// 	printf("%d\n", el_amount.n_here_doc);
// 	printf("%d\n", el_amount.n_red_in);
// 	printf("%d\n", el_amount.n_red_out);
// 	printf("%d\n", el_amount.n_red_out_app);
// 	printf("%d\n", el_amount.idx_cmd_flags);
// 	printf("%d\n", el_amount.idx_here_doc);
// 	printf("%d\n", el_amount.idx_red_in);
// 	printf("%d\n", el_amount.idx_red_out);
// 	printf("%d\n", el_amount.idx_red_out_app);
// }
