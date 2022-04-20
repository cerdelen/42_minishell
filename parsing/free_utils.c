/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:05:09 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/20 17:20:49 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	free_cmd_struct(t_cmd cmd)
{
	free_2d_array(cmd.cmd_flags);
	free_2d_array(cmd.input);
	free_2d_array(cmd.output);
}

void	free_cmd_struct_arr(t_cmd *cmd, int command_amt)
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
