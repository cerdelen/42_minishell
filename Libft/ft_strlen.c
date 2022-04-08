/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:54:30 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:54:30 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Computes the length of the string s.
*	The strnlen() function attempts to compute the length of s, but never scans
*	beyond the first maxlen bytes of s.
*
* Return Values
*	The number of characters that precede the terminating NUL character. 
*/

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
