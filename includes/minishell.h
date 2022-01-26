/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 03:05:19 by jin-lee          ###   ########.fr       */
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

# define SQUOTE	34
# define DQUOTE	39

/* Tools */
void	loop(void);


/* sanchpa#1, Readline -> Tokenize */
int	record_history(char *str);
int	check_expression(char *str);

//parsing
char**	parsing(char *str);

void	tokenize(char *str, t_tlist *token_list);

//signal
void	sig_handler(int signal);
void	setting_signal();

#endif