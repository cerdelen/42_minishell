/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/16 21:15:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void init_el_am(char **elements, t_n_el *el_amount)
{
	int i;
	
	ft_bzero(el_amount, sizeof(t_n_el));
	i = 0;
	// if (!elements)
	// 	return ;
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
			cmd.reddir_out_app[el_amount.idx_red_out_app++] = ft_strdup(elements[i] + 2);
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
	free_2d_array(elements);
	return (cmd);
}

// t_full_pipe *fill_cmd_struct(char **arr, int cmd_amt)
// {
// 	t_full_pipe	*compl_cmds;
// 	int i = 0;
// 	compl_cmds = malloc(sizeof(t_full_pipe) * cmd_amt);
// 	while(i < cmd_amt)
// 	{
// 		compl_cmds[i] = fill_cmd(arr[i]);
// 		i++;
// 	}
// 	return (compl_cmds);
// }
// int main()
// {
// 	t_n_el el_amount;
// 	char *string = "<<here_doc >>sth  $USER $?";
// 	char **arr = modified_split(string, ' ');

