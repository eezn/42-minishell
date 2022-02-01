# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:36:01 by jin-lee           #+#    #+#              #
#    Updated: 2022/02/02 01:02:00 by sangchpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

# Cluster
READLINE_DIR	= -l readline -L ~/.brew/opt/readline/lib
READLINE_CFLAGS	= -I ~/.brew/opt/readline/include

# jin-lee local workspace
# READLINE_DIR	= -l readline -L /opt/homebrew/opt/readline/lib
# READLINE_CFLAGS	= -I /opt/homebrew/opt/readline/include

# sangchpa local workspace
# READLINE_DIR	= -l readline -L /usr/local/opt/readline/lib
# READLINE_CFLAGS	= -I /usr/local/opt/readline/include

LIBFT			= ./libft/libft.a

INCS_DIR		= ./includes
SRCS_DIR		= ./srcs \
				  ./srcs/tools \
				  ./srcs/data_structure \
				  ./srcs/prompt \
				  ./srcs/built_in

SRCS			= ./srcs/main.c \
				  ./srcs/tools/loop.c \
				  \
				  ./srcs/data_structure/list_token.c \
				  ./srcs/data_structure/list_token_utils.c \
				  ./srcs/data_structure/list_env.c \
				  ./srcs/data_structure/list_env_utils.c \
				  \
				  ./srcs/prompt/record_history.c \
				  ./srcs/prompt/is_valid_line.c \
				  ./srcs/prompt/get_token_list.c \
				  ./srcs/prompt/signal.c \
				  \
				  ./srcs/built_in/built_in_env.c \
				  ./srcs/built_in/built_in_export.c \
				  ./srcs/built_in/built_in_unset.c \
				  ./srcs/built_in/built_in_cd.c \
				  ./srcs/built_in/built_in_pwd.c \
				  ./srcs/built_in/built_in_echo.c \
				  ./srcs/built_in/built_in_check.c \
				  ./srcs/built_in/arg_split.c \
				  ./srcs/built_in/filter.c \
				  ./srcs/built_in/heredoc.c \


OBJS_DIR		= ./objects
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM				= rm -f


all: $(NAME)


# minishell
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CDEBUG) $(READLINE_DIR) $^ -o $@
	@echo "\033[32m"$(NAME) built successfully."\033[0m"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -I $(INCS_DIR) $(READLINE_CFLAGS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $@


# library
$(LIBFT):
	@$(MAKE) -C ./libft all


# clean, fclean, re
clean:
	@$(MAKE) -C ./libft clean
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all, $(NAME), clean, fclean, re