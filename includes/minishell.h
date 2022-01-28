/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/29 06:50:23 by jin-lee          ###   ########.fr       */
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

# define SQUOTE	34
# define DQUOTE	39

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
char	*ft_strldup(char *src, int len);
char	*ft_ltrim(char *str);
char	*ft_rtrim(char *str);
char	*ft_trim(char *str);

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
void	test_trim(void);

#endif