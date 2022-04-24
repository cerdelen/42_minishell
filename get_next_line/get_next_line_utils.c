/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:33:05 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/12/13 21:33:05 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a1;
	const char	*a2;

	a1 = (char *) dest;
	a2 = (const char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		a1[i] = a2[i];
		i++;
	}
	return (dest);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			gnl_memcpy(dest + n, src + n, 1);
		}
		return (dest);
	}
	else
	{
		while (i < n)
		{
			gnl_memcpy(dest + i, src + i, 1);
			i++;
		}
	}
	return (dest);
}

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (NULL);
}
