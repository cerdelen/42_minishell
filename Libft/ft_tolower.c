/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:25:43 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:25:43 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Converts an upper-case letter to the corresponding lower-case letter.
*	The argument must be representable as an unsigned char or the value of EOF.
*
* Return Values
*	If the argument is an upper-case letter, the tolower() function returns the
*	corresponding lower-case letter if there is one; otherwise, the argument is
*	returned unchanged.
*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
