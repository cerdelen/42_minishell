/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:25:37 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 02:25:37 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Tests for an ASCII character, which is between 0 and 127 dez (0177 octal)
*	inclusive.
*
* Return Values
*	Returns 1 if the character tests true and 0 otherwise.
*/

int	ft_isascii(int c)
{
	if (c < 0 || c >= 128)
		return (0);
	return (1);
}
