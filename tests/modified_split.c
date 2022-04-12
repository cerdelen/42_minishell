/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 11:59:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/minishell.h"
#include <stdbool.h>
#include <stdio.h>

bool quotes_are_closed_no_loop(char c);

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*a;

	a = (char *) s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a1;
	const char	*a2;

	a1 = (char *) dest;
	a2 = (const char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		a1[i] = a2[i];
		i++;
	}
	return (dest);
}

int word_amount(const char *string, char c)
{
	int idx = 0;
	int w_count = 1;
	char character;
	while (string[idx])
	{
		character = string[idx];
		if (quotes_are_closed_no_loop(character) == false)
		{
			idx++;
			continue;
		}
			
		if (character== c)
		{
			w_count++;
		}
		idx++;
	}
	return (w_count);
}

char *init_string(char const *s, char c)
{
	int i = 0;
	int len = 0;
	char *str;
	bool status;
	while (s[len])
	{
		status = quotes_are_closed_no_loop(s[len]);
		if (status && s[len] == c)
			break;
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
	char	curr_char;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	ptr = malloc((word_amount(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		curr_char = s[i];
		if (quotes_are_closed_no_loop(s[i - 1]) == false)
		{
			i++;
			continue;
		}
		if (s[i] == 0)
			break ;
		if(count == 0 || s[i - 1] == c)
			ptr[count++] = init_string(s + i, c);
		
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

void print_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void free_2d_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool quotes_are_closed_no_loop(char c)
{
	static bool d_quotes_open = false;
	static bool s_quotes_open = false;

	if (c == '\'' && !d_quotes_open)
	{
		if (s_quotes_open)
			s_quotes_open = false;
		else
			s_quotes_open = true;
	}
	else if (c == '\"' && !s_quotes_open)
	{
		if (d_quotes_open)
			d_quotes_open = false;
		else
			d_quotes_open = true;
	}
	if (!d_quotes_open && !s_quotes_open)
		return (true);
	return (false);
}


// int main()
// {
// 	char **words;
// 	// words = modified_split("My|name|is|Kristiyana|Milcheva", '|');
	
// 	// words = modified_split("grep '|' input3.txt|awk '{print $1}' > output3.txt ", '|');
// 	words = modified_split("No pipes in this line", '|');
// 	// words = modified_split("cmd1 'fla|gs'|cmd2 'flags and pipes|||'|cmd3 \"quote|s and shit \' \' \"|more?", '|');
// 	print_2d_array(words);
// 	free_2d_array(words);
// }