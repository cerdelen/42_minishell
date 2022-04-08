/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:24:02 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 01:24:02 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Allocates sufficient memory for a copy of the string s1, does the copy,
*	and returns a pointer to it.  The pointer may subsequently be used as an
*	argument to the function free(3).
*
* Return Values
*	A pointer to the duplicate of the string, or
*	NULL if the Allocation fails.
*/

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = malloc(len * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}
