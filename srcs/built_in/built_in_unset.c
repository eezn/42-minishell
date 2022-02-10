/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:22 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/10 11:18:40 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(curr->key);
	free(curr->value);
	free(curr);
}

void	built_in_unset(char **token, t_elist *elist)
{
	t_env	*curr;
	t_env	*prev;
	int		i;

	i = 1;
	while (token[i])
	{
		curr = elist->head;
		prev = elist->head;
		while (curr)
		{
			if (!ft_strncmp(curr->key, token[i], ft_strlen(token[i])) \
				&& (ft_strlen(curr->key) == ft_strlen(token[i])))
				break ;
			prev = curr;
			curr = curr->next;
		}
		inner_unset(elist, curr, prev);
		i++;
	}
}
