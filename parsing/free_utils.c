/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:05:09 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/16 11:51:33 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
void free_cmd_struct(t_full_pipe cmd)
{
	free_2d_array(cmd.cmd_flags);
	free_2d_array(cmd.here_doc);
	free_2d_array(cmd.reddir_in);
	free_2d_array(cmd.reddir_out);
	free_2d_array(cmd.reddir_out_app);
}

void free_cmd_struct_arr(t_full_pipe *cmd, int command_amt)
{
	int i;

	i = 0;
	while (i < command_amt)
	{
		free_cmd_struct(cmd[i]);
		i++;
	}
	free(cmd);
}
void free_env_struct(t_env *envv, int i)
{
	int j;
	j = 0;
	while (j < i)
	{
		free(envv[j].var);
		free(envv[j].val);
		j++;
	}
	free(envv);
}

void free_2d_array(char **arr)
{
	int i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void free_struct_array(t_full_pipe *arr, int n_elements)
{
	int i;

	i = 0;
	while (i < n_elements)
	{
		free_2d_array(arr[i].reddir_in);
		free_2d_array(arr[i].reddir_out);
		free_2d_array(arr[i].here_doc);
		free_2d_array(arr[i].reddir_out_app);
		i++;
	}
	free(arr);
}
