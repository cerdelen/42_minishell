/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:26 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 16:02:26 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Description
*	Applies the function ’f’ to each character of the string ’s’, and
*	passing its index as first argument to create a new string (with malloc(3))
*	resulting from successive applications of ’f’.
*
* Parameters
*	#1. The string on which to iterate.
*	#2. The function to apply to each character.
*
* Return Values
*	The string created from the successive applications of ’f’.
*	Returns NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	int		len;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) + 1;
	str = ft_calloc(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
