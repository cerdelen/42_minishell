/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:27:38 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:27:38 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Locates the last occurrence of c (converted to a char) in the string pointed
*	to by s.  The terminating null character is considered to be part of the
*	string; therefore if c is \\0, the functions locate the terminating \\0.
*
* Return Values
*	A pointer to the located character,
*	or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *) s;
	i = ft_strlen(s);
	while (i > -1)
	{
		if (ptr[i] == c)
		{
			return (ptr + i);
		}
		i--;
	}
	return (0);
}
