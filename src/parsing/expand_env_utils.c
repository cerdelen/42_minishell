/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:34:24 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 17:49:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static bool	char_available(char *string, int i, int status)
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

static void	get_start_idx(char *string, int i, int *start_idx, int status)
{
	if (string[i] == '$')
	{
		if (string[i + 1] && (!ft_isalnum(string[i + 1])
				&& string[i + 1] != '?'))
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

static void	get_end_idx(char *str, int i, int *end_idx)
{
	i += 1;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '?'))
	{
		i++;
		if (str[i - 2] == '$' && str[i - 1] == '?')
			break ;
		if (str[i - 1] == '?')
		{
			i--;
			break ;
		}
	}
	*end_idx = i - 1;
}

int	get_indices(char *str, int *start_idx, int *end_idx)
{
	int	i;
	int	status;

	status = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			status = single_quotes_open(status);
		else if (str[i] == '\"')
			status = double_quotes_open(status);
		get_start_idx(str, i, start_idx, status);
		if (*start_idx)
			get_end_idx(str, i, end_idx);
		if (*end_idx)
			break ;
	}
	if (*start_idx != 0)
		return (0);
	return (1);
}
