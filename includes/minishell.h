/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 14:55:33 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/includes/libft.h"
# include "ms_macro.h"
# include "ms_data_struct.h"
# include "ms_built_in.h"

typedef struct s_pv	t_pv;

/* parse valuable */
struct s_pv
{
	char	*start;
	char	*end;
	char	curr_quote;
};

/* Tools */
char	*ft_strldup(char *src, int len);
char	*ft_ltrim(char *str);
char	*ft_rtrim(char *str);
char	*ft_trim(char *str);
void	horizon_bar(char c, char *color);
void	color_str(char *str, char *color);

/* Prompt : Readline, Tokenize */
void	main_debug(char **envp, char *test_line);
void	main_loop(char **envp);
int		line_history(char *str);
int		line_syntax(char *str);
void	set_token_list(char *str, t_tlist **tlist);
void	set_env_list(char **envp, t_elist **elist);

/* Execute */
char	**temp_envp(t_elist *elist);
char	**temp_args(t_node *astree);
void	clear_args(char **args);

void	exec(t_tlist *tlist, t_elist *elist);
void	inner_exec(t_node *astree, t_elist *elist);
void	exec_cmd(t_node *astree, t_elist *elist);
void	exec_pipe(t_node *astree, t_elist *elist);
void	exec_rdr(t_node *astree, t_elist *elist);

/* Signal */
void	sig_parent(int signal);
void	sig_execve(int signal);
void	setting_parent_signal(void);
void	setting_execve_signal(void);

#endif
