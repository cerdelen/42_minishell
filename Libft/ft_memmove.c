/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:31:56 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/22 15:31:56 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Copies n bytes from string src to string dst.
*	The two strings may overlap; the copy is always done in a non-destructive
*	manner.
*
* Return Values
*	The original value of dst.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
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
			ft_memcpy(dest + n, src + n, 1);
		}
		return (dest);
	}
	else
	{
		while (i < n)
		{
			ft_memcpy(dest + i, src + i, 1);
			i++;
		}
	}
	return (dest);
}
