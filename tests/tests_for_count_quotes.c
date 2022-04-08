/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_for_count_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:27:25 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/08 15:27:36 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main ()
{
	printf("Number of quotes: %d Should be: 0\n", count_chars("Some quotes", '\''));
	printf("Number of quotes: %d Should be: 0\n", count_chars("Some quotes", '\"'));
	printf("Number of quotes: %d Should be: 4\n", count_chars("Some \'\'\'\'quotes", '\''));
	printf("Number of quotes: %d Should be: 0\n", count_chars("Some \'\'\'\'quotes", '\"'));
	printf("Number of quotes: %d Should be: 0\n", count_chars("Some \"\"\"\"quotes", '\''));
	printf("Number of quotes: %d Should be: 4\n", count_chars("Some \"\"\"\"quotes", '\"'));
	printf("Number of quotes: %d Should be: 2\n", count_chars("Some \"\'\"\'quotes", '\"'));
	printf("Number of quotes: %d Should be: 3\n", count_chars("Some \"\'\"\'\'quotes", '\''));
	return (0);
}