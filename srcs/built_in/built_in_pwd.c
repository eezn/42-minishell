/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:29 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/09 23:30:56 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_pwd(char **token, t_elist *elist)
{
	char	cwd[1024];

	if (token[1] != 0)
	{
		elist->exit_status = -1;
		printf("pwd: too many arguments\n");
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
	}
}
