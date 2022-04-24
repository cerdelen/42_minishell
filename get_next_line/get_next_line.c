/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:34:45 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/12/13 21:34:45 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeandreturn(char *str1, char *buff)
{
	free(buff);
	return (str1);
}

void	store_remainder(char *remainder, char **remainderarr, int fd)
{
	int		strlen;
	char	*allocremainder;

	strlen = gnl_strlen(remainder);
	if (strlen > 0)
	{
		allocremainder = malloc((strlen + 1) * sizeof(char));
		gnl_memmove(allocremainder, remainder, strlen);
		allocremainder[strlen] = '\0';
		remainderarr[fd] = allocremainder;
	}
	else
		remainderarr[fd] = NULL;
}

char	*get_line(char *str1, char **remainderarr, int fd, char *buff)
{
	char	*out;
	char	*remainder;
	int		strlen;

	remainder = (gnl_strchr(str1, '\n') + 1);
	store_remainder(remainder, remainderarr, fd);
	remainder[0] = '\0';
	strlen = gnl_strlen(str1);
	out = malloc((strlen + 1) * sizeof(char));
	gnl_memmove(out, str1, strlen + 1);
	free(str1);
	free(buff);
	return (out);
}

char	*appending(char *str1, char *str2)
{
	char	*out;
	int		len1;
	int		len2;

	len2 = gnl_strlen(str2);
	len1 = 0;
	if (str1)
		len1 = gnl_strlen(str1);
	out = malloc((len1 + len2 + 1) * sizeof(char));
	if (str1)
		gnl_memmove(out, str1, len1);
	gnl_memmove(out + len1, str2, len2);
	out[len1 + len2] = '\0';
	if (str1)
		free(str1);
	return (out);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*readstr;
	int				readret;
	static char		*remainder[1024];

	readstr = NULL;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (remainder[fd])
	{
		readstr = appending(readstr, remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
		if (gnl_strchr(readstr, '\n'))
			return (get_line(readstr, remainder, fd, buff));
	}
	readret = read(fd, buff, BUFFER_SIZE);
	while (readret > 0)
	{
		buff[readret] = '\0';
		readstr = appending(readstr, buff);
		if (gnl_strchr(readstr, '\n'))
			return (get_line(readstr, remainder, fd, buff));
		readret = read(fd, buff, BUFFER_SIZE);
	}
	return (freeandreturn(readstr, buff));
}
