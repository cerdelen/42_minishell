/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:05:09 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 13:49:54 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	free_cmd_struct(t_full_pipe cmd)
{
	free_2d_array(cmd.cmd_flags);
	free_2d_array(cmd.here_doc);
	free_2d_array(cmd.input);
	free_2d_array(cmd.output);
	free_2d_array(cmd.out_append);
}

void	free_cmd_struct_arr(t_full_pipe *cmd, int command_amt)
{
	int	i;

	i = 0;
	while (i < command_amt)
	{
		free_cmd_struct(cmd[i]);
		i++;
	}
	free(cmd);
	cmd = NULL;
}

void	free_env_struct(t_env *envv, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(envv[j].var);
		envv[j].var = NULL;
		free(envv[j].val);
		envv[j].val = NULL;
		j++;
	}
	free(envv);
	envv = NULL;
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_struct_array(t_full_pipe *arr, int n_elements)
{
	int	i;

	i = 0;
	while (i < n_elements)
	{
		free_2d_array(arr[i].input);
		free_2d_array(arr[i].output);
		free_2d_array(arr[i].here_doc);
		free_2d_array(arr[i].out_append);
		i++;
	}
	free(arr);
	arr = NULL;
}
