# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:55:48 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/10 11:18:59 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# one:
# 	gcc k_readline.c -lreadline libft.a && ./a.out

SRC = main.c parse_input.c utils.c modified_split.c redirection.c
LIB_PATH = ../Libft

test:
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) clean -C $(LIB_PATH)
	
	gcc $(SRC) -L$(LIB_PATH) -l:libft.a