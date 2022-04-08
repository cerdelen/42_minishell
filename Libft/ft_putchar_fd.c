/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:06:10 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 02:06:10 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Outputs the character ’c’ to the given file descriptor.
*
* Parameters
*	#1. The character to output.
*	#2. The file descriptor on which to write.
*
* Return Values
*	the number of characters written (1)
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
