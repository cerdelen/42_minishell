# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:55:48 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/08 16:17:31 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# one:
# 	gcc k_readline.c -lreadline libft.a && ./a.out

SRC = main.c parse_input.c
LIB_PATH = ../Libft
split:
	gcc modified_split.c && ./a.out
	
test:
	$(MAKE) clean -C $(LIB_PATH)
	$(MAKE) -C $(LIB_PATH)
	gcc $(SRC) -L$(LIB_PATH) -l:libft.a