/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:58:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/11 09:23:57 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
// #include "../includes/libft.h"
#include "../includes/minishell.h"
#include "../Libft/libft.h"

void remove_blank_spaces(char **string)
{
	char *new;
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while((*string)[i])
	{
		if (quotes_are_closed_no_loop(temp[i]) && temp[i] == ' ' && temp[i + 1] == ' ')
		{
			i++;
			continue ;
		}
		new[j++] = temp[i];
		i++;
	}
	// printf("\nFUNCTION: %s\n", new);
	new[j] = '\0';
	// free(temp);
	new = ft_strtrim(new, " ");
	*string = ft_strdup(new);
	free(new);
	free(temp);
}

// int main ()
// {
// 	char *word;
	
// 	word = ft_strdup("     K   h   e   l  o       ");
// 	printf("\nBEFOR: %s\n", word);
// 	remove_blank_spaces(&word);
// 	printf("\nAFTER:%sXXXXXXXXXX", word);
// 	free(word);
// }

