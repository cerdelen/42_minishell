/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:58:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/20 21:26:56 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"
#include "../includes/minishell.h"

void	remove_blank_spaces(char **string)
{
	char	*new;
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while ((*string)[i])
	{
		if (quotes_are_closed(temp[i]) && temp[i] == ' '
			&& temp[i + 1] && temp[i + 1] == ' ')
		{
			i++;
			continue ;
		}
		new[j++] = temp[i++];
	}
	reset_quotes();
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

int	ft_isspace(char c)
{
	return ((c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v'));
}

void	replace_white_spaces(char **string)
{
	char	*new;
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while ((*string)[i])
	{
		if (quotes_are_closed(temp[i]) && ft_isspace(temp[i]))
		{
			new[j++] = ' ';
			i++;
			continue ;
		}
		new[j++] = temp[i++];
	}
	reset_quotes();
	new[j] = '\0';
	free(temp);
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
}

void	connect_singular_angular_braces(char **string)
{
	char	*new;
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = 0;
	new = ft_strdup(*string);
	while ((*string)[++i])
	{
		if (quotes_are_closed((*string)[i])
			&& (i > 0)
			&& ((*string)[i - 1] == '>' || (*string)[i - 1] == '<')
			&& (*string)[i] == ' ')
			continue ;
		new[j++] = (*string)[i];
	}
	new[j] = '\0';
	free((*string));
	temp = ft_strtrim(new, " ");
	*string = ft_strdup(temp);
	free(new);
	free(temp);
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
