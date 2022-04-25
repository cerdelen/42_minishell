# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 09:59:43 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/25 12:44:12 by Cerdelen         ###   ########.fr        #
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

SRC_EXECUTOR =	cer/ms_command_exec.c \
				cer/ms_command_opening_fds.c \
				cer/ms_find_executable_path.c cer/open_access_files.c \
				cer/utils.c

MAIN_SRC = main.c

LIB = libft.a

LIB_PATH = ../Libft

# FLAGS = -Wall -Werror -Wextra

SPECIAL_FLAG =  -lreadline

all: $(NAME)

$(NAME): $(LIB_PATH)/$(LIB)
	gcc $(FLAGS) $(MAIN_SRC) $(SRC_EXECUTOR) $(SRC_PARSER) $(LIB_PATH)/$(LIB)  $(SPECIAL_FLAG) -o $(NAME)

#$(LIB_PATH)/$(LIB):
#	$(MAKE) -C $(LIB_PATH)
#	$(MAKE) clean -C $(LIB_PATH)

fclean:
	rm -f $(NAME)
#	rm -f $(LIB_PATH)/$(LIB)

re: fclean all