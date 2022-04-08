/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:57:52 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 13:57:52 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Iterates the list ’lst’ and applies the function
*	’f’ to the content of each element.
*
*
* Parameters
*	#1. The adress of a pointer to an element.
*	#2. The adress of the function used to iterate on
*	the list.
*
* Return Values
*	None
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr -> content)
			(*f)(ptr->content);
		ptr = ptr->next;
	}
}
