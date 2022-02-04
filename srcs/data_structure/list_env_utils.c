/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:08:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 19:14:04 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env	*env)
{
	if (env)
		printf("%s=%s\n", env->key, env->value);
}

void	print_env_list(t_elist *elist)
{
	t_env	*curr;

	curr = elist->head;
	while (curr)
	{
		print_env(curr);
		curr = curr->next;
	}
}

t_env	*get_env_by_key(t_elist *elist, char *key)
{
	t_env	*curr;

	curr = elist->head;
	while (curr)
	{
		if (!ft_strncmp(curr->key, key, ft_strlen(key)) \
			&& (ft_strlen(curr->key) == ft_strlen(key)))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
