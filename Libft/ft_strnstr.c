/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:30:34 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:30:34 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Locates the first occurrence of the null-terminated string needle in the
*	string haystack, where not more than n characters are searched.
*	Characters that appear after a NUL character are not searched.
*
* Parameters
*	#1. The string haystack to be search in
*	#2. The string needle to be search for
*
* Return Values
*	If needle is an empty string, haystack is returned;
*	if needle occurs nowhere in haystack, NULL is returned;
*	otherwise a pointer to the first character of the first occurrence of needle
*	is returned.
*/

char	*ft_strnstr(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;
	char			*a1;
	char			*a2;

	if (!s1 || !s2)
		return (NULL);
	a1 = (char *) s1;
	a2 = (char *) s2;
	i = 0;
	len1 = ft_strlen(a1);
	len2 = ft_strlen(a2);
	if (len2 == 0)
		return (a1);
	while (i + len2 <= n && i + len2 <= len1)
	{
		if (a1[i] == a2[0])
			if (ft_strncmp (a1 + i, a2, len2) == 0)
				return (a1 + i);
		i++;
	}
	return (0);
}
