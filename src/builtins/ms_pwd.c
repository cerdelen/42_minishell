/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:50:31 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 13:50:32 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_pwd(void)
{
	char	*completepath;
	int		i;

	i = 10;
	completepath = malloc(i * sizeof(char));
	getcwd(completepath, i);
	while (errno == ERANGE)
	{
		errno = 0;
		i = i + 10;
		free(completepath);
		completepath = malloc(i * sizeof(char));
		getcwd(completepath, i);
	}
	printf("%s\n", completepath);
	free(completepath);
	return (0);
}
