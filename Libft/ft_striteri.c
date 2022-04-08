/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:10:53 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 16:10:53 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Applies the function f to each character of the string passed as argument,
*	and passing its index as first argument. Each character is passed by address
*	to f to be modified if necessary.
*
* Parameters
*	#1. The string on which to iterate.
*	#2. The function to apply to each character.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s != NULL && (*f) != NULL)
	{
		while (s[i] != '\0')
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
