# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 09:59:43 by kmilchev          #+#    #+#              #
#    Updated: 2022/05/08 19:40:25 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_PARSER =	src/parsing/parse_input.c \
				src/parsing/parse.c\
				src/parsing/modified_split.c \
				src/parsing/error_management.c \
				src/parsing/error_management2.c \
				src/parsing/manipulate_string.c \
				src/parsing/expand_env.c \
				src/parsing/expand_env_utils.c \
				src/parsing/print_utils.c \
				src/parsing/free_utils.c \
				src/parsing/utils.c \
				src/parsing/quotes_management.c \
				src/parsing/quotes_removal.c \

SRC_EXECUTOR =	src/execution/ms_command_exec.c \
				src/execution/ms_command_opening_fds.c \
				src/execution/ms_find_executable_path.c \
				src/execution/ms_find_executable_path_utils.c \
				src/execution/open_access_files.c \
				src/execution/utils.c \
				src/execution/utils2.c \
				src/execution/ms_here_doc.c \
				src/execution/handling_builtins.c \
				src/execution/forking_and_executing.c \

SRC_BUILTINS =	src/builtins/ms_export.c \
				src/builtins/ms_unset.c \
				src/builtins/ms_cd.c \
				src/builtins/ms_env.c \
				src/builtins/ms_echo.c \
				src/builtins/ms_exit.c \
				src/builtins/ms_pwd.c
				
SRC_SIGNALS =	src/signals/signals.c \
				src/signals/signals2.c

MAIN_SRC = src/main.c

LIB = libft.a

LIB_PATH = Libft

#FLAGS = -Wall -Werror -Wextra

SPECIAL_FLAG =  -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

all: $(NAME)

$(NAME): $(LIB_PATH)/$(LIB)
	@gcc $(FLAGS) $(MAIN_SRC) $(SRC_EXECUTOR) $(SRC_PARSER) $(SRC_BUILTINS) $(SRC_SIGNALS) $(LIB_PATH)/$(LIB)  $(SPECIAL_FLAG) -o $(NAME)
	@echo "\033[92mminshell successfully compiled!\033[0m"

$(LIB_PATH)/$(LIB):
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) clean -C $(LIB_PATH)

fclean:
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -f $(NAME) $(LIB_PATH)/$(LIB)
	@echo "\033[91mminishell successfully cleaned!\033[91m"

re: fclean all