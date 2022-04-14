/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:20:41 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/14 10:21:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"

char	*find_single_redirection(char *string, char symbol, t_r_s *vars)
{
	char	*sub_str;

	vars->i = 0;
	vars->j = 0;
	vars->len = 0;
	sub_str = ft_strdup(string);
	while (string[vars->i])
	{
		if (quotes_are_closed(string[vars->i]) && string[vars->i] == symbol)
		{
			vars->start_index = vars->i;
			sub_str[vars->j++] = string[++vars->i];
			while (string[vars->i + 1] && string[vars->i] == ' ')
				sub_str[vars->j++] = string[++vars->i];
			while (string[vars->i + 1] && string[vars->i + 1] != ' '
				&& string[vars->i + 1] != '\0'
				&& string[vars->i + 1] != symbol)
				sub_str[vars->j++] = string[++vars->i];
			sub_str[vars->j] = '\0';
			vars->finish_index = vars->i;
			break ;
		}
		vars->i++;
	}
	return (sub_str);
}

char	*trim_string(char *str, char*sub, t_r_s *vars)
{
	int		str_len;
	int		sub_len;
	int		i;
	int		j;
	char	*new_str;

	str_len = ft_strlen(str);
	sub_len = ft_strlen(sub) - 1;
	new_str = ft_calloc(str_len - sub_len, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < vars->start_index || i > vars->finish_index)
			new_str[j++] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

char	**get_single_redirections(char **string, char symbol, t_r_s *vars)
{
	int		n_redir;
	char	**redir;
	int		i;
	char	*buf;

	buf = ft_strdup(*string);
	n_redir = count_chars(buf, symbol);
	redir = (char **)ft_calloc(n_redir + 1, sizeof(char *));
	i = 0;
	while (i < n_redir)
	{
		redir[i] = find_single_redirection(buf, symbol, vars);
		buf = trim_string(buf, redir[i], vars);
		i++;
	}
	redir[i] = NULL;
	free(*string);
	*string = ft_strdup(buf);
	free(buf);
	return (redir);
}

char	*find_double_redirection(char *string, char symbol, t_r_s *vars)
{
	char	*sub_str;

	vars->i = 0;
	vars->j = 0;
	vars->len = 0;
	sub_str = malloc(sizeof(char) * ft_strlen(string) + 1);
	while (string[vars->i + 2])
	{
		// if (vars->i == 1 || string[vars->i - 1] != ' ')
		// {
			if (quotes_are_closed(string[vars->i]) && string[vars->i] == symbol && string[vars->i++ + 1] == symbol)
			{
				vars->start_index = vars->i - 1;
				sub_str[vars->j++] = string[++vars->i];
				while (string[vars->i + 1] && string[vars->i] == ' ')
					sub_str[vars->j++] = string[++vars->i];
				while (string[vars->i + 1] && string[vars->i + 1] != ' '
					&& string[vars->i + 1] != '\0'
					&& string[vars->i + 2] != symbol)
					sub_str[vars->j++] = string[++vars->i];
				sub_str[vars->j] = '\0';
				vars->finish_index = vars->i;
				break ;
			}
		// }
		vars->i++;
	}
	return (sub_str);
}

char	**get_double_redirections(char **string, char symbol, t_r_s *vars)
{
	int		n_redir;
	char	**redir;
	int		i;
	char	*buf;

	buf = ft_strdup(*string);
	n_redir = count_double_chars(buf, symbol);
	redir = (char **)ft_calloc(n_redir + 1, sizeof(char *));
	i = 0;
	while (i < n_redir)
	{
		redir[i] = find_double_redirection(buf, symbol, vars);
		buf = trim_string(buf, redir[i], vars);
		i++;
	}
	redir[i] = NULL;
	free(*string);
	*string = ft_strdup(buf);
	free(buf);
	return (redir);
}

