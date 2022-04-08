/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_signals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:21:16 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/07 13:10:17 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../42_libft/libft.h"
#include <signal.h>

void handler(int sig)
{
	// printf("Semeczniki\n");
	char *line;
	line = readline("kis619_shell >\n");
	//printf("\n");
	free(line);
}

int main(int argc, char *argv[], char *envv[])
{
	char *line;
	signal(SIGINT, handler);

	while(1)
	{
		line = readline("kis619_shell >");
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
			add_history(line);
		free(line);
	}
}
