/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:00:58 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 19:49:33 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_el_am(char **elements, t_n_el *el_amount)
{
	int	i;

	ft_bzero(el_amount, sizeof(t_n_el));
	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0 || '>' == elements[i][0])
			el_amount->n_red_out++;
		else if (ft_strncmp("<<", elements[i], 2) == 0 || '<' == elements[i][0])
			el_amount->n_red_in++;
		else
			el_amount->n_cmd_flags++;
		i++;
	}
}

static void	init_cmd_struct(t_cmd *cmd, t_n_el *el_amount, char **arr)
{
	init_el_am(arr, el_amount);
	cmd->cmd_flags = ft_calloc(el_amount->n_cmd_flags + 1, sizeof(char *));
	cmd->input = ft_calloc(el_amount->n_red_in + 1, sizeof(char *));
	cmd->output = ft_calloc(el_amount->n_red_out + 1, sizeof(char *));
	cmd->cmd_flags[el_amount->n_cmd_flags] = NULL;
	cmd->input[el_amount->n_red_in] = NULL;
	cmd->output[el_amount->n_red_out] = NULL;
}

static void	distribute_strings(char **elements, t_n_el n_el, t_cmd *cmd)
{
	int	i;

	i = 0;
	while ((elements[i]))
	{
		if (ft_strncmp(">>", elements[i], 2) == 0)
			cmd->output[n_el.idx_red_out++] = ft_strdup(elements[i]);
		else if (ft_strncmp("<<", elements[i], 2) == 0)
			cmd->input[n_el.idx_red_in++] = ft_strdup(elements[i]);
		else if ('<' == elements[i][0])
			cmd->input[n_el.idx_red_in++] = ft_strjoin("< ", elements[i] + 1);
		else if ('>' == elements[i][0])
			cmd->output[n_el.idx_red_out++] = ft_strjoin("> ", elements[i] + 1);
		else
		{
			remove_quotes(&elements[i]);
			cmd->cmd_flags[n_el.idx_cmd_flags++] = ft_strdup(elements[i]);
		}
		i++;
	}
}

t_cmd	fill_cmd(char *string)
{
	char	**elements;
	t_cmd	cmd;
	t_n_el	el_amount;

	if (!string || string[0] == '\0')
	{
		ft_bzero(&cmd, sizeof(cmd));
		return (cmd);
	}
	elements = modified_split(string, ' ');
	init_cmd_struct(&cmd, &el_amount, elements);
	distribute_strings(elements, el_amount, &cmd);
	free_2d_array(elements);
	return (cmd);
}

t_cmd	*fill_cmds_struct(char *string, t_ms_data *data)
{
	int		i;
	char	**arr;
	t_cmd	*compl_cmds;

	if (string[0] == '\0')
		ft_bzero(&compl_cmds, sizeof(t_cmd));
	else
	{
		arr = modified_split(string, '|');
		data->command_amt = count_chars(string, '|') + 1;
		compl_cmds = ft_calloc((data->command_amt), sizeof(t_cmd));
		i = 0;
		while (i < data->command_amt)
		{
			compl_cmds[i] = fill_cmd(arr[i]);
			i++;
		}
		free_2d_array(arr);
	}
	free(string);
	return (compl_cmds);
}
