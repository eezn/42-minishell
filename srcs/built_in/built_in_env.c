/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:17 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 19:13:45 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_env(char **token, t_elist *elist)
{
	if (token[1] != 0)
		printf("env: too many arguments\n");
	else
		print_env_list(elist);
}
