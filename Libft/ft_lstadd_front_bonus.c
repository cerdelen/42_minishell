/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:54:40 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 13:54:40 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Adds the element ’new’ at the beginning of the list.
*
* Parameters
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a pointer to the element to be added to the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (*lst)
		temp = *lst;
	*lst = new;
	new->next = temp;
}
