/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:39:09 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 17:39:09 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Allocates (with malloc(3)) and returns a new string, which is the result of
*	the concatenation of ’s1’ and ’s2’.
*
* Parameters
*	#1. The prefix string.
*	#2. The suffix string.
*
* Return Values
*	The new string.
*	NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ptr;
	char	*a1;
	char	*a2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a1 = (char *) s1;
	a2 = (char *) s2;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, a1, len1);
	ft_memcpy(ptr + len1, a2, len2);
	return (ptr);
}
