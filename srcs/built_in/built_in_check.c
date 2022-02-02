/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:59:30 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/02 20:35:49 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_in_check(char **token, t_elist *elist)
{	
	if(ft_strnstr("echo", token[0], ft_strlen("echo")) != 0 && \
		ft_strlen(token[0]) == ft_strlen("echo"))
		built_in_echo(token);
	else if(ft_strnstr("pwd", token[0], ft_strlen("pwd")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("pwd"))
		built_in_pwd(token);
	else if(ft_strnstr("cd", token[0], ft_strlen("cd")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("cd"))
		built_in_cd(token, elist);
	else if(ft_strnstr("env", token[0], ft_strlen("env")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("env"))
		built_in_env(token, elist);
	else if(ft_strnstr("export", token[0], ft_strlen("export")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("export"))
		built_in_export(token, elist);
	else if(ft_strnstr("unset", token[0], ft_strlen("unset")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("unset"))
		built_in_unset(token, elist);
	else if(ft_strnstr("exit", token[0], ft_strlen("exit")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("exit"))
		exit(1);
	else
		return 1;
	return 0;			
}
