/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:48:09 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 13:48:09 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Outputs the integer ’n’ to the given file descriptor.
*
* Parameters
*	#1. The integer to output.
*	#2. The file descriptor on which to write.
*
* Return Values
*	the number of characters written
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

static	void	stringcreate(int dig, int n, char *ptr)
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
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dig;
	char	ptr [12];

	dig = digits(n);
	stringcreate(dig, n, ptr);
	ft_putstr_fd(ptr, fd);
}
