/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:33:42 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/12/13 21:33:42 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>

# include <stdlib.h>

char	*get_next_line(int fd);
char	*appending(char *str1, char *str2);
char	*get_line(char *str1, char **remainderarr, int fd, char *buff);
char	*gnl_strchr(const char *s, int c);
int		gnl_strlen(const char *s);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
void	*gnl_memmove(void *dest, const void *src, size_t n);

#endif
