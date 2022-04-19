/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:34:24 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 13:34:46 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

bool	char_available(char *string, int i, int status)
{
	if (status == S_OPEN_ONLY || status == D_OPEN_SECOND)
		return (false);
	else if (status == NONE_OPEN
		&& (string[i + 1] == '\0'
			|| string[i + 1] == '\"'
			|| string[i + 1] == '\''))
		return (false);
	else if (status == NONE_OPEN && string[i + 1] && string[i + 1] == ' ' )
		return (false);
	else if ((status == NONE_OPEN) && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == S_OPEN_SECOND && string[i + 1] && string[i + 1] == '?')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == '\"')
		return (false);
	else if (status == D_OPEN_ONLY && string[i + 1] && string[i + 1] == ' ')
		return (false);
	else
		return (true);
}

bool	char_is_present(char c, char *string)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (string[i])
	{
		if (string[i] == '\'')
			status = single_quotes_open(status);
		else if (string[i] == '\"')
			status = double_quotes_open(status);
		else if (string[i] == c)
		{	
			if (char_available(string, i, status))
				return (true);
		}
		i++;
	}
	return (false);
}

void	get_start_idx(char *string, int i, int *start_idx, int status)
{
	if (string[i] == '$')
	{
		if (string[i + 1] && string[i + 1] == '?')
		{
			*start_idx = 0;
		}
		else if (string[i + 1] && string[i + 1] == ' ')
		{
			*start_idx = 0;
		}
		else if (status == NONE_OPEN
			|| status == D_OPEN_ONLY || status == S_OPEN_SECOND)
		{
			if (string[i + 1] && string[i + 1] != '\"')
				*start_idx = i + 1;
		}
	}
}

int	get_indices(char *str, int *start_idx, int *end_idx)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			status = single_quotes_open(status);
		else if (str[i] == '\"')
			status = double_quotes_open(status);
		get_start_idx(str, i, start_idx, status);
		if (*start_idx)
		{
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
				i++;
			*end_idx = i - 1;
		}
		i++;
		if (*end_idx)
			break ;
	}
	if (*start_idx != 0)
		return (0);
	return (1);
}
