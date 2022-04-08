/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:05:29 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 01:05:29 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Copy strings with the same input parameters and output result as snprintf(3).
*	Designed to be safer, more consistent, and less error prone replacements for
*	the easily misused function strncpy(3).
*	Take the full size of the destination buffer and guarantee NUL-termination
*	if there is room. Note that room for the NULL should be included in dstsize.
*	Appends string src to the end of dst.
*	Copies up to dstsize - 1 characters from the string src to dst,
*	NUL-terminating the result if dstsize is not 0.
*	If the src and dst strings overlap, the behavior is undefined.

* Return Values
*	The total length of the string tried to create.
*	-> length of src
*	If the return value is >= dstsize, the output string has been truncated.
*	It is the caller's responsibility to handle this.
*/

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
