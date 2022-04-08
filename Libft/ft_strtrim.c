/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:57:45 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 00:57:45 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
*	specified in ’set’ removed from the beginning and the end of the string.
*
* Parameters
*	#1. The string to be trimmed.
*	#2. The reference set of characters to trim.
*
* Return Values
*	The trimmed string.
*	NULL if the allocation fails.
*/

static int	findstart(char const *set, char const *s1)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i++;
		if (s1[i] == 0)
			return (-1);
	}
	return (i);
}

static int	findend(char const *set, char const *s1, int i)
{
	while (ft_strchr(set, s1[i]) != NULL)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = findstart(set, s1);
	end = ft_strlen(s1);
	if (start < 0 || s1[0] == 0)
		ptr = ft_calloc(1, sizeof(char));
	if ((start < 0 || s1[0] == 0) && ptr == NULL)
		return (NULL);
	if (s1[0] == 0)
		return (ptr);
	if (!set)
		ft_strlcpy(ptr, s1, end + 1);
	if (!set || start < 0)
		return (ptr);
	end = findend(set, s1, end - 1);
	ptr = ft_calloc((end - start) + 2, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, end - start + 2);
	return (ptr);
}
