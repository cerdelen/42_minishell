/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:37:31 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/22 23:37:31 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Converts the string into an integer representation.
*
*	The string may begin with an arbitrary amount of white space (as determined
*	by isspace) followed by a single optional `+' or `-' sign. It is assumed
*	that the number is in base 10. The conversion stops at the first character
*	that is not a valid digit.
*
* Return Values
*	the resulting int from the conversion
*/

static int	checksign(const char *ptr)
{
	if (ptr[0] == '+')
		return (1);
	if (ptr[0] == '-')
		return (2);
	return (0);
}

static int	makenumber(int i, const char *start)
{
	int	x;
	int	nmb;

	nmb = 0;
	x = 1;
	while (i > -1)
	{	
		nmb -= (start[i] - 48) * x;
		x *= 10;
		i--;
	}
	return (nmb);
}

int	ft_atoi(const char *nptr)
{
	int			nmb;
	int			i;
	const char	*start;
	int			sign;

	nmb = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	sign = checksign(&nptr[i]);
	if (sign > 0)
		i++;
	start = (const char *) nptr + i;
	i = 0;
	while (ft_isdigit(start[i]) == 1)
		i++;
	i--;
	nmb = makenumber(i, start);
	if (sign == 0 || sign == 1)
		nmb = nmb * (-1);
	return (nmb);
}
