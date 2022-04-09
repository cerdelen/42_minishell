/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:20:41 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 16:48:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char *find_single_redirection(char *string, char symbol, t_r_s *vars)
{
	
	char *sub_str;
	vars->i = 0;
	vars->j = 0;
	vars->len = 0;
	sub_str = malloc(200);
	while (string[vars->i])
	{
		if (quotes_are_closed_no_loop(string[vars->i]) && string[vars->i] == symbol)
		{
			vars->start_index = vars->i;
			sub_str[vars->j++] = string[vars->i++];
			while(string[vars->i + 1] == ' ')
				sub_str[vars->j++] = string[vars->i++ + 1];
			while(string[vars->i + 1] != ' ' && string[vars->i + 1] != '\0')
				sub_str[vars->j++] = string[vars->i++ + 1];
			sub_str[vars->j] = '\0';
			vars->finish_index = vars->i;
		}
		vars->i++;
	}
	return (sub_str);
}

char *trim_string(char *str, char*sub, t_r_s *vars)
{
	int str_len;
	int sub_len;
	int i;
	int j;
	char *new_str;
	
	str_len = ft_strlen(str);
	sub_len = ft_strlen(sub) - 1;
	new_str = malloc(sizeof(char) * str_len - sub_len);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < vars->start_index || i > vars->finish_index)
			new_str[j++] = str[i];
		i++;
	}
	
	return (new_str);
}

char **get_single_redirection(char *string, char symbol, t_r_s *vars)
{
	int n_redir;
	char **redir;
	int i;
	
	n_redir = count_chars(string, symbol);
	redir = (char **)malloc(sizeof(char *) * n_redir);
	i = 0;
	while (i < n_redir)
	{
		redir[i] = find_single_redirection(string, symbol, vars);x
		i++;
	}

	return (redir);
}