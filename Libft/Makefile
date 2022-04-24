# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:13:17 by Cerdelen          #+#    #+#              #
#    Updated: 2021/11/22 17:13:17 by Cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

AR = ar rcs

NAME = libft.a

SRCS = 	ft_split.c\
		ft_itoa.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_memcpy.c\
		ft_atoi.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_strrchr.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_tolower.c\
		ft_toupper.c

BONUS = ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
	   	ft_lstsize_bonus.c\
	   	ft_lstlast_bonus.c\
	   	ft_lstadd_back_bonus.c\
	   	ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_B = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): 
	$(CC) $(CFLAGS) -c $(SRCS)

$(OBJS_B): 
	$(CC) $(CFLAGS) -c $(BONUS)

all: $(NAME)

bonus: fclean $(OBJS_B) $(OBJS)
	$(AR) $(NAME) $(OBJS_B) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: bonus all clean fclean re
