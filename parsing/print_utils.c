/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:03:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/16 13:20:09 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void print_cmd_struct(t_full_pipe cmd)
{
	// int i = 0;
	
	printf("-----------\nCMD_FLAGS:\n");
	print_2d_array(cmd.cmd_flags);
	printf("-----------\nHERE_DOC:\n");
	print_2d_array(cmd.here_doc);
	printf("-----------\nRED_IN:\n");
	print_2d_array(cmd.reddir_in);
	printf("-----------\nRED_OUT:\n");
	print_2d_array(cmd.reddir_out);
	printf("-----------\nRED_OUT_APP:\n");
	print_2d_array(cmd.reddir_out_app);
	// while(cmd.cmd_flags[i])
	// 	printf("CMD_FLAG: %s\n", cmd.cmd_flags[i++]);
	// i = 0;	
	// while(cmd.here_doc[i])
	// 	printf("HERE_DOC: %s\n", cmd.here_doc[i++]);
	// i = 0;	
	// while(cmd.reddir_in[i])
	// 	printf("REDIRECT_INPUT: %s\n", cmd.reddir_in[i++]);
	// i = 0;	
	// while(cmd.reddir_out[i])
	// 	printf("REDIRECT_OUTPUT: %s\n", cmd.reddir_out[i++]);
	// i = 0;	
	// while(cmd.reddir_out_app[i])
	// 	printf("REDIRECT_OUT_APP: %s\n", cmd.reddir_out_app[i++]);
}

void print_cmd_struct_arr(t_full_pipe *arr, int command_amt)
{
	int i = 0;
	while(i < command_amt)
	{
		print_cmd_struct(arr[i]);
		printf("**********************\n");
		i++;
	}
}
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
		printf("%s\n", arr[i]);
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
