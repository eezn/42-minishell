/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:22 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 19:18:52 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

/* 함수 이름 임시 */
static void	inner_unset(t_elist *elist, t_env *curr, t_env *prev)
{
	if (curr == NULL)
		return ;
	else if (curr == elist->head)
	{
		if (curr == elist->tail)
			elist->tail = NULL;
		elist->head = curr->next;
	}
	else if (curr == elist->tail)
	{
		elist->tail = prev;
		prev->next = NULL;
	}
	else
		prev->next = curr->next;
	elist->count--;
	free(curr);
}

void	built_in_unset(t_elist *elist, char *key)
{
	t_env	*curr;
	t_env	*prev;

	curr = elist->head;
	prev = elist->head;
	while (curr)
	{
		if (!ft_strncmp(curr->key, key, ft_strlen(key)) \
			&& (ft_strlen(curr->key) == ft_strlen(key)))
			break ;
		prev = curr;
		curr = curr->next;
	}
	inner_unset(elist, curr, prev);
}
