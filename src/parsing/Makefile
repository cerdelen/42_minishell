# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:55:48 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/24 09:29:04 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC	=	main.c parse_input.c parse.c\
		modified_split.c \
		error_management.c error_management2.c \
		remove_spaces.c \
		expand_env.c expand_env_utils.c \
		print_utils.c free_utils.c utils.c \
		quotes_management.c quotes_removal.c 
		
LIB_PATH = ../../Libft
# FLAGS = -Wall -Werror -Wextra

test:
	# $(MAKE) -C $(LIB_PATH)
	# $(MAKE) clean -C $(LIB_PATH)
	
	gcc $(SRC) $(FLAGS) -L$(LIB_PATH) -lft
