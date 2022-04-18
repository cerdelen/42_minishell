/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/18 13:39:58 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	str = ft_memcpy(str, s, len);
	reset_quotes();
	return (str);
}

char	**modified_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	ptr = ft_calloc((word_amount(s, c) + 1), sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (count && quotes_are_closed(s[i - 1]) == false)
		{
			i++;
			continue ;
		}
		if (s[i] == 0)
			break ;
		if (count == 0 || s[i - 1] == c)
		{
			temp = init_string(s + i, c);
			if (temp)
			{
				ptr[count++] = temp;
			}
		}
		i++;
	}
	reset_quotes();
	ptr[count] = NULL;
	return (ptr);
}
