/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:55:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/07 12:16:46 by kmilchev         ###   ########.fr       */
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

//To use the readline library specify -lreadline to your compiler.
int main(int argc, char *argv[], char *envv[])
{
	char *line;
	// char cwd[PATH_MAX];
	
	while(1)
	{
		line = readline("kis619_shell >");
		if (ft_strlen(line) > 0)
			add_history(line);
		printf("%s\n", line);
		free(line);
	}
}

