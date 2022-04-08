/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:31:52 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 02:31:52 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Tests for any character for which isalpha or isdigit is true.
*
* Return Values
*	Returns 1 if the character tests true and 0 otherwise.
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
