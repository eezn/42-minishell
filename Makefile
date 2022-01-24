# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:36:01 by jin-lee           #+#    #+#              #
#    Updated: 2022/01/19 16:50:14 by jin-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

LIBFT		= ./libft/libft.a

INCS_DIR	= ./includes
SRCS_DIR	= ./srcs \
			  ./srcs/tools \
			  ./srcs/data_structure

SRCS		= ./srcs/main.c \
			  ./srcs/tools/loop.c \
			  ./srcs/data_structure/syntax.c \
			  ./srcs/data_structure/token_list.c

OBJS_DIR	= ./objects
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM			= rm -f


all: $(NAME)


# minishell
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CDEBUG) $^ -o $@
	@echo "\033[32m"$(NAME) built successfully."\033[0m"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -I $(INCS_DIR) -c $^ -o $@

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