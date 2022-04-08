/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:25:04 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 00:25:04 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Converts an lower-case letter to the corresponding lower-case letter.
*	The argument must be representable as an unsigned char or the value of EOF.
*
* Return Values
*	If the argument is an lower-case letter, the tolower() function returns the
*	corresponding upper-case letter if there is one; otherwise, the argument is
*	returned unchanged.
*/

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}
