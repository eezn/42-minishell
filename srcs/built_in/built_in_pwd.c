/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:29 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/04 19:13:40 by jin-lee          ###   ########.fr       */
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