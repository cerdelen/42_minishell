/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:03:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 13:49:54 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	print_cmd_struct(t_full_pipe cmd)
{
	printf("-----------\nCMD_FLAGS:\n");
	print_2d_array(cmd.cmd_flags);
	printf("-----------\nHERE_DOC:\n");
	print_2d_array(cmd.here_doc);
	printf("-----------\nRED_IN:\n");
	print_2d_array(cmd.input);
	printf("-----------\nRED_OUT:\n");
	print_2d_array(cmd.output);
	printf("-----------\nRED_OUT_APP:\n");
	print_2d_array(cmd.out_append);
}

void	print_cmd_struct_arr(t_full_pipe *arr, int command_amt)
{
	int	i;

	i = 0;
	while (i < command_amt)
	{
		print_cmd_struct(arr[i]);
		printf("**********************\n");
		i++;
	}
}

void	print_env_struct(t_env *envv, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		printf("Variable: %s == ", envv[j].var);
		printf("Value: %s\n", envv[j].val);
		j++;
	}
}

void	print_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%sX\n", arr[i]);
		i++;
	}
}
