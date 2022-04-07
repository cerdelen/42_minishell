/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:13:16 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/07 10:42:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	char cwd[PATH_MAX];
	// printf("Obfuscation");
	while(1)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s >\n", cwd);
		else
		{
			perror("FUCK YOU");
			return (1);
		}
		sleep(1);
	}
	return 0;
}
