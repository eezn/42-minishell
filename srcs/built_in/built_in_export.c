/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:20 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 17:58:39 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

/* 이미 존재하는 key -> update, 존재하지 않는 key -> append */
void	built_in_export(t_elist *elist, char *key, char *value)
{
	t_env	*env;

	env = get_env_by_key(elist, key);
	if (env)
		env->value = value;
	else
		append_env(elist, key, value);
}
