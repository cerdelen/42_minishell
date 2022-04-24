/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/24 09:27:49 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	word_amount(const char *string, char c)
{
	int		idx;
	int		w_count;
	char	character;

	idx = 0;
	w_count = 1;
	while (string[idx])
	{
		character = string[idx];
		if (quotes_are_closed(character) == false)
		{
			idx++;
			continue ;
		}
		if (character == c)
			w_count++;
		idx++;
	}
	reset_quotes();
	return (w_count);
}

char	*init_string(char const *s, char c)
{
	int		len;
	char	*str;
	bool	status;

	len = 0;
	while (s[len])
	{
		status = quotes_are_closed(s[len]);
		if (status && s[len] == c)
			break ;
		len++;
	}
	if (len == 0)
	{
		reset_quotes();
		return (NULL);
	}
	str = ft_calloc(len + 1, sizeof(char));
	str = ft_memcpy(str, s, len);
	reset_quotes();
	return (str);
}

char	**modified_split(char const *s, char c)
{
	t_data	d;

	d.i = -1;
	d.count = 0;
	if (!s)
		return (NULL);
	d.ptr = ft_calloc((word_amount(s, c) + 1), sizeof(char *));
	if (d.ptr == NULL)
		return (NULL);
	while (s[++d.i] != 0)
	{
		if (d.count && quotes_are_closed(s[d.i - 1]) == false)
			continue ;
		if (s[d.i] == 0)
			break ;
		if (d.count == 0 || s[d.i - 1] == c)
		{
			d.temp = init_string(s + d.i, c);
			if (d.temp)
				d.ptr[d.count++] = d.temp;
		}
	}
	reset_quotes();
	d.ptr[d.count] = NULL;
	return (d.ptr);
}
