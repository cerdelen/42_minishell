/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:07:10 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 01:07:10 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Copy and concatenate strings with the same input parameters and output result
*	as snprintf(3).
*	Designed to be safer, more consistent, and less error prone replacements for
*	the easily misused function strncat(3).
*	Take the full size of the destination buffer and guarantee NUL-termination
*	if there is room. Note that room for the NULL should be included in dstsize.
*	Appends string src to the end of dst.
*	It will append at most dstsize - strlen(dst) - 1 characters.  It will then
*	NUL-terminate, unless dstsize is 0 or the original dst string was longer than
*	dstsize (in practice this should not happen as it means that either dstsize
*	is incorrect or that dst is not a proper string).
*	If the src and dst strings overlap, the behavior is undefined.

* Return Values
*	The total length of the string tried to create.
*	-> initial length of dst plus the length of src
*	If the return value is >= dstsize, the output string has been truncated.
*	It is the caller's responsibility to handle this.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len1;
	size_t			len2;

	i = 0;
	len2 = ft_strlen(src);
	len1 = 0;
	if (size == 0)
		return (len1 + len2);
	while (dst[len1] != '\0')
	{
		if (len1 == size - 1)
			return (len1 + len2 + 1);
		len1++;
	}
	while ((i < (size - len1 - 1)) && src[i] != '\0')
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	if (size < len1)
		return (len2 + size);
	else
		return (len1 + len2);
}
