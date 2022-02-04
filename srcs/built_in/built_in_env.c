/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:17 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/29 17:58:00 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	built_in_env(char **token, t_elist *elist)
{
	if (token[1] != 0)
		printf("env: too many arguments\n");
	else
		print_env_list(elist);
}
