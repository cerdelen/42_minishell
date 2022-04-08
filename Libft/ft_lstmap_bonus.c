/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:02:19 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/24 14:02:19 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
*	element. Creates a new list resulting of the successive applications of the
*	function ’f’. The ’del’ function is used to delete the content of an element
*	if needed. (e.g. if an allocation fails midway trough)
*
* Parameters
*	#1. The adress of a pointer to an element.
*	#2. The adress of the function used to iterate on the list.
*	#3. The adress of the function used to delete the content of an element if
*		needed.
*
* Return Values
*	The new list.
*	NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	result_list = ft_lstnew(f(lst->content));
	if (!result_list)
		return (NULL);
	ptr = result_list;
	lst = lst->next;
	while (lst)
	{
		result_list->next = ft_lstnew(f(lst->content));
		if (!result_list->next)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		result_list = result_list->next;
		lst = lst->next;
	}
	result_list->next = NULL;
	return (ptr);
}
