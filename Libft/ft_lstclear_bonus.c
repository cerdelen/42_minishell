/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:55:59 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 13:55:59 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Deletes and frees the given element and every successor of that element,
*	using the function ’del’ and free(3).
*	Finally, the pointer to the list is set to NULL.
*
* Parameters
*	#1. The address of a pointer to tan element.
*	#2. The address of the function used to delete the content of the element.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *lst;
	while (ptr->next != NULL)
	{
		temp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = temp;
	}
	ft_lstdelone(ptr, del);
	lst = NULL;
}
