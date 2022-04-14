/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:03:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/14 10:04:44 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void print_env_struct(t_env *envv, int i)
{
	int j;
	j = 0;
	while (j < i)
	{
		printf("Variable: %s == ", envv[j].var);
		printf("Value: %s\n", envv[j].val);
		j++;
	}
}

void print_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%sX\n", arr[i]);
		i++;
	}
}

void print_struct_array(t_full_pipe *arr, int n_elements)
{
	int i;

	i = 0;
	while (i < n_elements)
	{
		printf("\nELEMENT %d ---------------------\n", i);
		if (arr[i].reddir_in)
		{
			printf("Redirection in:\n");
			print_2d_array(arr[i].reddir_in);
		}
		if (arr[i].reddir_out)
		{
			printf("Redirection out:\n");
			print_2d_array(arr[i].reddir_out);
		}
		if (arr[i].reddir_out_app)
		{
			printf("Double Redirection out:\n");
			print_2d_array(arr[i].reddir_out_app);
		}
		if (arr[i].here_doc)
		{
			printf("Here_doc Redirection :\n");
			print_2d_array(arr[i].here_doc);
		}
		if (arr[i].cmd_flags)
		{
			printf("COMMAND and FLAGS: \n");
			print_2d_array(arr[i].cmd_flags);
		}
		i++;
	}
}
