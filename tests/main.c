/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:46:44 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/09 11:30:46 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main()
{
	char *string;
	string = "whatev||'|'||er";
	printf("Quotes are closed: %d\n", quotes_are_closed(string));
	printf("Number of pipes: %d\n", count_chars(string, '|'));

}