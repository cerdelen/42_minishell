/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:35:16 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 01:35:16 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Writes len bytes of value c (converted to an unsigned char) to the string b.
*
* Return Values
*	Its first argument.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*a;

	a = (char *) s;
	i = 0;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (s);
}
