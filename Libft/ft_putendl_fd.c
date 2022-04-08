/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:11:04 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 02:11:04 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Outputs the string ’s’ to the given file descriptor, followed by a newline.
*
* Parameters
*	#1. The string to output.
*	#2. The file descriptor on which to write.
*
* Return Values
*	the number of characters written
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
