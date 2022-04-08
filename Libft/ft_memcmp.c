/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:59:03 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 01:59:03 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Compares byte string s1 against byte string s2.
*	Both strings are assumed to be n bytes long.
*
* Return Values
*	0 if the two strings are identical, otherwise returns the difference between
*	the first two differing bytes (treated as unsigned char values, so that \\200
*	is greater than \\0, for example).  Zero-length strings are always identical.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*a1;
	unsigned char	*a2;
	int				r;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (a1[i] != a2[i])
		{
			r = a1[i] - a2[i];
			return (r);
		}
		i++;
	}
	r = 0;
	return (r);
}
