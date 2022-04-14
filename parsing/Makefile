# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:55:48 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/14 10:08:24 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.c parse_input.c utils.c modified_split.c redirection.c error_management.c remove_spaces.c expand_env.c print_utils.c free_utils.c quotes_management.c
LIB_PATH = ../Libft
# FLAGS = -Wall -Werror -Wextra

test:
	# $(MAKE) -C $(LIB_PATH)
	# $(MAKE) clean -C $(LIB_PATH)
	
	gcc $(SRC) $(FLAGS) -L$(LIB_PATH) -lft

env:
	gcc quotes_management.c print_utils.c free_utils.c expand_env.c parse_input.c utils.c libft.a