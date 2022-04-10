/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:44:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/10 16:48:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void print_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
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
		i++;
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
//counts how many instances of a character are present in a string
//returns -1 if either of the arguments is not present
int count_chars(char *str, char c)
{
	int idx;
	int count;
	
	if (!str || !c)
		return (-1);
	idx = 0;
	count = 0;
	while (str[idx])
	{
		if (quotes_are_closed_no_loop(str[idx]) && str[idx] == c)
			count++;
		idx++;
	}
	return (count);
}

int count_double_chars(char *str, char c)
{
	int idx;
	int count;
	
	if (!str || !c)
		return (-1);
	idx = 0;
	count = 0;
	while (str[idx + 2])
	{
		if (quotes_are_closed_no_loop(str[idx]) && str[idx] == c && str[idx + 1] == c)
			count++;
		idx++;
	}
	while (str[idx])
	{
		quotes_are_closed_no_loop(str[idx++]);
	}
	
	return (count);
}
