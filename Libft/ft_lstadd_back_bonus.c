/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:54:10 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 13:54:10 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Adds the element ’new’ at the end of the list.
*
* Parameters
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a pointer to the element to be added to the list.
*/

//void	ft_lstadd_back(t_list **lst, t_list *new)
//{
//	t_list	*ptr;
//
//	ptr = ft_lstlast(*lst);
//	if (!ptr)
//		return (*lst = new);
//	ptr->next = new;
//}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		if (!(*lst))
			*lst = new;
		else
			(ft_lstlast(*lst))->next = new;
	}
}
