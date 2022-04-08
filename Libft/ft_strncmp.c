/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:46:02 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:46:02 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Lexicographically compare the null-terminated strings s1 and s2.
*	Compares not more than n characters. characters that appear after a NUL
*	character are not compared.
*
* Return Values
*	An integer greater than, equal to, or less than 0, according as the string
*	s1 is greater than, equal to, or less than the string s2. The comparison is
*	done using unsigned characters, so that \\200 is greater than \\0.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				r;
	unsigned char	*a1;
	unsigned char	*a2;

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
		if (a1[i] == '\0' && a2[i] == '\0')
		{
			r = 0;
			return (r);
		}
		i++;
	}
	r = 0;
	return (r);
}
