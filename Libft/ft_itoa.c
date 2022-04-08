/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:01:43 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 02:01:43 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Allocates (with malloc(3)) and returns a string representing the integer
*	received as an argument.
*	Negative numbers are handled.
*
* Return Values
*	The string representing the integer.
*	NULL if the allocation fails.
*/

static int	digits(int n)
{
	int	dig;
	int	x;

	dig = 1;
	x = n;
	if (n >= 0)
	{
		while (x >= 10)
		{
			dig += 1;
			x /= 10;
		}
	}
	if (n < 0)
	{
		while (x <= -10)
		{
			dig += 1;
			x /= 10;
		}
	}
	return (dig);
}

static char	*stringcreate(int dig, int n, char *ptr)
{
	if (n < 0)
	{
		ptr[0] = '-';
		dig += 1;
		ptr[dig] = 0;
		while (dig > 1)
		{
			ptr[dig - 1] = ((n % 10) * (-1)) + 48;
			n /= 10;
			dig--;
		}
	}
	else
	{
		ptr[dig] = 0;
		while (dig > 0)
		{
			ptr[dig - 1] = (n % 10) + 48;
			n /= 10;
			dig--;
		}
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*ptr;

	dig = digits(n);
	if (n < 0)
		ptr = malloc(dig + 2 * sizeof(char));
	else
		ptr = malloc(dig + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = stringcreate(dig, n, ptr);
	return (ptr);
}
