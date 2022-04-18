/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 19:26:35 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	init_el_am(char **elements, t_n_el *el_amount)
{
	int	i;

	ft_bzero(el_amount, sizeof(t_n_el));
	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0)
			el_amount->n_app_out++;
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

void	init_cmd_struct(t_full_pipe *cmd, t_n_el *el_amount, char **arr)
{
	init_el_am(arr, el_amount);
	cmd->cmd_flags = ft_calloc(el_amount->n_cmd_flags + 1, sizeof(char *));
	cmd->here_doc = ft_calloc(el_amount->n_here_doc + 1, sizeof(char *));
	cmd->input = ft_calloc(el_amount->n_red_in + 1, sizeof(char *));
	cmd->output = ft_calloc(el_amount->n_red_out + 1, sizeof(char *));
	cmd->out_append = ft_calloc(el_amount->n_app_out + 1, sizeof(char *));
	cmd->cmd_flags[el_amount->n_cmd_flags] = NULL;
	cmd->here_doc[el_amount->n_here_doc] = NULL;
	cmd->input[el_amount->n_red_in] = NULL;
	cmd->output[el_amount->n_red_out] = NULL;
	cmd->out_append[el_amount->n_app_out] = NULL;
}

void	distribute_strings(char **elements, t_n_el n_el, t_full_pipe *cmd)
{
	int	i;

	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0)
			cmd->out_append[n_el.idx_app_out++] = ft_strdup(elements[i] + 2);
		else if (ft_strncmp("<<", elements[i], 2) == 0)
			cmd->here_doc[n_el.idx_here_doc++] = ft_strdup(elements[i] + 2);
		else if ('<' == elements[i][0])
			cmd->input[n_el.idx_red_in++] = ft_strdup(elements[i] + 1);
		else if ('>' == elements[i][0])
			cmd->output[n_el.idx_red_out++] = ft_strdup(elements[i] + 1);
		else
		{
			remove_quotes(&elements[i]);
			cmd->cmd_flags[n_el.idx_cmd_flags++] = ft_strdup(elements[i]);
		}
		i++;
	}
}

t_full_pipe	fill_cmd(char *string)
{
	char		**elements;
	t_full_pipe	cmd;
	t_n_el		el_amount;

	if (!string || string[0] == '\0') //NEED TO CHECK THIS WITH THE MAC
	{
		ft_bzero(&cmd, sizeof(t_full_pipe));
		return (cmd);
	}
	elements = modified_split(string, ' ');
	init_cmd_struct(&cmd, &el_amount, elements);
	distribute_strings(elements, el_amount, &cmd);
	free_2d_array(elements);
	return (cmd);
}

t_full_pipe	*fill_cmds_struct(char *string, int *command_amt)
{
	int			i;
	char		**arr;
	t_full_pipe	*compl_cmds;

	arr = modified_split(string, '|');
	*command_amt = count_chars(string, '|') + 1;
	compl_cmds = ft_calloc((*command_amt), sizeof(t_full_pipe));
	i = 0;
	while (i < *command_amt)
	{
		compl_cmds[i] = fill_cmd(arr[i]);
		i++;
	}
	free_2d_array(arr);
	free(string);
	return (compl_cmds);
}
