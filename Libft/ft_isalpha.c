/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:27:16 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 02:27:16 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Tests for any character for which isupper or islower is true.
*
* Return Values
*	Returns 1 if the character tests true and 0 otherwise.
*/

int	ft_isalpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	if (c > 96 && c < 123)
		return (1);
	return (0);
}
