# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 09:59:43 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/24 10:28:42 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_PARSER =	parsing/parse_input.c parsing/parse.c\
				parsing/modified_split.c \
				parsing/error_management.c parsing/error_management2.c \
				parsing/remove_spaces.c \
				parsing/expand_env.c parsing/expand_env_utils.c \
				parsing/print_utils.c parsing/free_utils.c parsing/utils.c \
				parsing/quotes_management.c parsing/quotes_removal.c \
				# parsing/main.c 

SRC_EXECUTOR = 

MAIN_SRC = main.c

LIB = libft.a

LIB_PATH = ../Libft

FLAGS = -Wall -Werror -Wextra

SPECIAL_FLAG =  -lreadline

all: $(NAME)

$(NAME): $(LIB_PATH)/$(LIB)
	gcc $(FLAGS) $(SPECIAL_FLAG) $(MAIN_SRC) $(SRC_EXECUTOR) $(SRC_PARSER) $(LIB_PATH)/$(LIB) -o $(NAME)

$(LIB_PATH)/$(LIB):
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) clean -C $(LIB_PATH)

fclean:
	rm -f $(NAME)
	rm -f $(LIB_PATH)/$(LIB)

re: fclean all