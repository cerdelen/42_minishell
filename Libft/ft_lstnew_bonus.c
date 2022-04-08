/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:04:11 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 14:04:11 by Cerdelen         ###   ########.fr       */
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
*	#1. The content to create the new element with.
*
* Return Values
*	The new element.
*	NULL if the allocation fails.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}
