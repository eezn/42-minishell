/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/28 18:55:21 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/includes/libft.h"
# include "data_structure.h"
# include "built_in.h"

# define SQUOTE	39
# define DQUOTE	34

typedef struct s_pv	t_pv;

/* parse valuable */
struct s_pv
{
	char	*start;
	char	*end;
	char	curr_quote;
};

/* Tools */
void	loop(void);

/* sanchpa#1, Readline -> Tokenize */
int		record_history(char *str);
int		is_valid_line(char *str);
void	get_token_list(char *str, t_tlist **tlist);

/* Signal */
void	sig_handler(int signal);
void	setting_signal(void);

/* Test Functions */
void	test_env_list(t_elist *elist);
void	test_unset(void);

#endif