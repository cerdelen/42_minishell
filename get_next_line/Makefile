# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:13:17 by Cerdelen          #+#    #+#              #
#    Updated: 2022/04/14 16:41:29 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror -I../includes

AR = ar rcs

NAME = get_next_line.a

SRCS = 	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): 
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -c $(SRCS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
