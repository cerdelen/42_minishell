/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:44:51 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/20 02:44:51 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Writes n zeroed bytes to the string s. If n is zero, it does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*a;

	a = (char *) s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
