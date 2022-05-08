/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_removal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:49:46 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 18:06:07 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	remove_quotes(char **string)
{
	char	*new;
	int		i;
	int		j;
	char	q;

	i = 0;
	j = 0;
	new = ft_strdup(*string);
	while ((*string)[i])
	{
		q = (*string)[i];
		if (q == '\'' || q == '"')
		{	
			i++;
			while ((*string)[i] && (*string)[i] != q)
				new[j++] = (*string)[i++];
			i++;
		}
		else
			new[j++] = (*string)[i++];
	}
	new[j] = '\0';
	free(*string);
	*string = ft_strdup(new);
	free(new);
}

void	remove_single_quotes(char **string, char rm, char keep)
{
	char	*new;
	int		i;
	int		j;
	char	*temp;
	int		status;

	status = 0;
	i = -1;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while ((*string)[++i])
	{
		if (temp[i] == keep)
			status = double_quotes_open(status);
		if (status != D_OPEN_ONLY && temp[i] == rm)
			continue ;
		new[j++] = temp[i];
	}
	new[j] = '\0';
	free(temp);
	*string = ft_strdup(new);
	free(new);
}

void	remove_double_quotes(char **string, char rm, char keep)
{
	char	*new;
	int		j;
	int		i;
	char	*temp;
	int		status;

	status = 0;
	i = -1;
	j = 0;
	new = ft_strdup(*string);
	temp = *string;
	while ((*string)[++i])
	{
		if (temp[i] == keep)
			status = single_quotes_open(status);
		if (status != S_OPEN_ONLY && temp[i] == rm)
			continue ;
		new[j++] = temp[i];
	}
	new[j] = '\0';
	free(temp);
	*string = ft_strdup(new);
	free(new);
}
