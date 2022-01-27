/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:29 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/27 17:03:49 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_in_pwd(char** tmp)
{
	char cwd[1024];

	if (tmp[1] != 0)
		printf("pwd: too many arguments\n");
	else
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
	}
	return 0;
}