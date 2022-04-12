/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/11 22:35:26 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/minishell.h"
#include <stdbool.h>
#include <stdio.h>
#include "../includes/parsing.h"

int	word_amount(const char *string, char c)
{
	int		idx;
	int		w_count;
	char	character;

	idx = 0;
	w_count = 1;
	while (string[idx])
	{
		character = string[idx];
		if (quotes_are_closed_no_loop(character) == false)
		{
			idx++;
			continue ;
		}
		if (character == c)
			w_count++;
		idx++;
	}
	return (w_count);
}

char	*init_string(char const *s, char c)
{
	int		len;
	char	*str;
	bool	status;

	len = 0;
	while (s[len])
	{
		status = quotes_are_closed_no_loop(s[len]);
		if (status && s[len] == c)
			break ;
		len++;
	}
	if (len == 0)
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	str = ft_memcpy(str, s, len);
	return (str);
}

char	**modified_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	ptr = ft_calloc((word_amount(s, c) + 1), sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (quotes_are_closed_no_loop(s[i - 1]) == false)
		{
			i++;
			continue ;
		}
		if (s[i] == 0)
			break ;
		if (count == 0 || s[i - 1] == c)
			ptr[count++] = init_string(s + i, c);
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

// int main()
// {
// 	char **words;
// 	// words = modified_split("My|name|is|Kristiyana|Milcheva", '|');

// 	// words = modified_split("grep '|' input3.txt|awk '{print $1}' > output3.txt ", '|');
// 	// words = modified_split("No pipes in this line", '|');
// 	words = modified_split("''|''|''", '|');
	// words = modified_split("cmd1 'fla|gs'|cmd2 'flags and pipes|||'|cmd3 \"quote|s and shit \' \' \"|more?", '|');
// 	print_2d_array(words);
// 	free_2d_array(words);
// }