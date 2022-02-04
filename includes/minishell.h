/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 19:24:53 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/includes/libft.h"
# include "data_structure.h"
# include "built_in.h"
# include "macro.h"

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
t_elist	*set_env_list(char **envp);

/* Execute */
void	exec(t_node *astree, t_elist *elist);
void	exec_cmd(t_node *astree, t_elist *elist);
void	exec_pipe(t_node *astree, t_elist *elist);
void	exec_rdr(t_node *astree, t_elist *elist);

/* Signal */
void	sig_parent(int signal);
void	sig_child(int signal);
void	setting_parent_signal();
void	setting_child_signal();

/* Test Functions */
void	test_env_list(t_elist *elist);
void	test_unset(void);
void	test_trim(void);

#endif
