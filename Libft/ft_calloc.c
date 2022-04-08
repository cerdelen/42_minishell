/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:38:49 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 02:38:49 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Contiguously allocates enough space for count objects that are size bytes of
*	memory each and returns a pointer to the allocated memory.
*	The allocated memory is filled with bytes of value zero.
*
* Return Values
*	If succsesfull, it returns a pointer to allocated memory,
*	otherwise returns NULL.
*/

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
