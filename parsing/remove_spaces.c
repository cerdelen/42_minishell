/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:58:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 12:23:28 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"
#include "../includes/minishell.h"

void remove_blank_spaces(char **string)
{
	char *new;
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (quotes_are_closed(temp[i]) && temp[i] == ' ' && temp[i + 1] && temp[i + 1] == ' ')
		{
			i++;
			continue ;
		}
		new[j++] = temp[i];
		i++;
	}
	// printf("\nFUNCTION: %s\n", new);
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

// char *remove_blank_spaces2(char *string)
// {
// 	char *new;
// 	char *temp;
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	new = ft_strdup(string);
// 	while(string[i])
// 	{
// 		if (quotes_are_closed(string[i]) && string[i] == ' ' && string[i + 1] == ' ')
// 		{
// 			i++;
// 			continue ;
// 		}
// 		else if (quotes_are_closed(string[i]) && string[i] != ' ' && string[i + 1] == ' ' && string[i + 2] == '|')
// 		{
// 			i++;
// 			continue ;
// 		}
// 		new[j++] = string[i];
// 		i++;
// 	}
// 	new[j] = '\0';
// 	temp = ft_strtrim(new, " ");
// 	string = ft_strdup(temp);
// 	free(new);
// 	free(temp);
// 	return (string);
// }

void connect_double_angular_braces(char **string)
{
	char *new;
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (quotes_are_closed(temp[i]) 
			&& (temp[i - 1] && temp[i - 2])
			&& (temp[i - 1] == '>' && temp[i - 2] == '>' || temp[i - 1] == '<' && temp[i - 2] == '<') 
			&& temp[i] == ' ')
		{
			i ++;
			continue ;
		}
		new[j++] = temp[i++];
	}
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

void connect_singular_angular_braces(char **string)
{
	char *new;
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (quotes_are_closed(temp[i]) 
			&& (temp[i - 1])
			&& (temp[i - 1] == '>' || temp[i - 1] == '<') 
			&& temp[i] == ' ')
		{
			i ++;
			continue ;
		}
		new[j++] = temp[i++];
	}
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

void remove_quotes(char **string)
{
	if ((*string)[0] == '\'')
		remove_single_quotes(string, '\'', '"');
	else if ((*string)[0] == '"')
		remove_double_quotes(string, '"', '\'');
}

void remove_single_quotes(char **string, char rm, char keep)
{
	char *new;
	int i;
	int j;
	char *temp;
	int status;

	status = 0;
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (temp[i] == keep)	
			status = double_quotes_open(status);
		if (status != D_OPEN_ONLY && temp[i] == rm)
		{
			i++;
			continue ;
		}
		new[j++] = temp[i];
		i++;
	}
	new[j] = '\0';
	free(temp);
	*string = ft_strdup(new);
	free(new);
}

void remove_double_quotes(char **string, char rm, char keep)
{
	char *new;
	int i;
	int j;
	char *temp;
	int status;

	status = 0;
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (temp[i] == keep)	
			status = single_quotes_open(status);
		if (status != S_OPEN_ONLY && temp[i] == rm)
		{
			i++;
			continue ;
		}
		new[j++] = temp[i];
		i++;
	}
	new[j] = '\0';
	free(temp);
	*string = ft_strdup(new);
	free(new);
}

void	disconnect_angular_braces(char **string)
{
	char	*new;
	char	*temp;
	int		size;
	int		i;
	int		j;

	temp = *string;
	size = 2 * ft_strlen(temp);
	new = malloc(sizeof(char) * size);
	i = 0;
	j = 0;
	while (temp[i])
	{
		if ((temp[i] == '>' || temp[i] == '<') && i && ft_isalnum(temp[i - 1]))
		{
			new[j++] = ' ';
		}
		new[j++] = temp[i++];
	}
	new[j] = '\0';
	*string = ft_strdup(new);
	free(new);
	free(temp);
}
