/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:03:55 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 14:03:55 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Allocates (with malloc(3)) and returns a new element. The variable ’content’
*	is initialized with the value of the parameter ’content’. 
*	The variable ’next’ is initialized to NULL.
*
* Parameters
*	#1. The beginning of the list.
*
* Return Values
*	The new element.
*	NULL if the allocation fails.
*/

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	ptr = lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
