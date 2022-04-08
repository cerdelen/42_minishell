/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:03:49 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/21 21:03:49 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Copies n bytes from memory area src to memory area dst.
*	If dst and src overlap, behavior is undefined.  Applications in which dst
*	and src might overlap should use memmove(3) instead.
*
* Return Values
*	The original value of dst.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
