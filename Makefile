# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 15:36:01 by jin-lee           #+#    #+#              #
#    Updated: 2022/02/05 04:51:29 by jin-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

# Cluster
# READLINE_HEADER	= -I ~/.brew/opt/readline/include
# READLINE_FOLDER	= -l readline -L ~/.brew/opt/readline/lib

# jin-lee local workspace
READLINE_HEADER	= -I /opt/homebrew/opt/readline/include
READLINE_FOLDER	= -l readline -L /opt/homebrew/opt/readline/lib

# sangchpa local workspace
# READLINE_HEADER	= -I /usr/local/opt/readline/include
# READLINE_FOLDER	= -l readline -L /usr/local/opt/readline/lib

LIBFT			= ./libft/libft.a

INCS_DIR		= ./includes
SRCS_DIR		= ./srcs \
				  ./srcs/tools \
				  ./srcs/data_structure \
				  ./srcs/prompt \
				  ./srcs/built_in \
				  ./srcs/exec \
				  ./srcs/etc

SRCS			= ./srcs/main.c \
				  \
				  ./srcs/tools/ft_strldup.c \
				  ./srcs/tools/ft_trim.c \
				  ./srcs/tools/horizon_bar.c \
				  ./srcs/tools/color_str.c \
				  \
				  ./srcs/data_structure/list_env.c \
				  ./srcs/data_structure/list_env_utils.c \
				  ./srcs/data_structure/list_token.c \
				  ./srcs/data_structure/list_token_utils.c \
				  ./srcs/data_structure/astree.c \
				  ./srcs/data_structure/insert_astree.c \
				  \
				  ./srcs/prompt/main_loop.c \
				  ./srcs/prompt/line_history.c \
				  ./srcs/prompt/line_syntax.c \
				  ./srcs/prompt/set_token_list.c \
				  ./srcs/prompt/set_env_list.c \
				  ./srcs/prompt/signal.c \
				  \
				  ./srcs/built_in/built_in_check.c \
				  ./srcs/built_in/built_in_cd.c \
				  ./srcs/built_in/built_in_echo.c \
				  ./srcs/built_in/built_in_env.c \
				  ./srcs/built_in/built_in_export.c \
				  ./srcs/built_in/built_in_unset.c \
				  ./srcs/built_in/built_in_pwd.c \
				  ./srcs/built_in/filter.c \
				  \
				  ./srcs/exec/exec_cmd.c \
				  ./srcs/exec/exec_pipe.c \
				  ./srcs/exec/exec_rdr.c \
				  ./srcs/exec/exec.c \
				  \
				  ./srcs/etc/heredoc.c


OBJS_DIR		= ./objects
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM				= rm -f


all: $(NAME)


# minishell
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CDEBUG) $(READLINE_FOLDER) $^ -o $@
	@echo "\033[32m"$(NAME) built successfully."\033[0m"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -I $(INCS_DIR) $(READLINE_HEADER) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $@


# libft
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