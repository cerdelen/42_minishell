/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_for_quotes_are_closed.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/08 15:45:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main ()
{
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\'\'\"\""));
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\'\"\'"));
	printf("Quotes are closed: %d, should be 1\n", quotes_are_closed("\"\'\""));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\'\""));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\'\"\'\"\'"));
	printf("Quotes are closed: %d, should be 0\n", quotes_are_closed("\"\'\"\'\"\'\""));
	return (0);
}