/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:26:19 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 03:11:52 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tlist	*create_token_list(void)
{
	t_tlist	*tlist;

	tlist = (t_tlist *)malloc(sizeof(t_tlist));
	if (!tlist)
		return (NULL);
	tlist->head = NULL;
	tlist->tail = NULL;
	tlist->count = 0;
	return (tlist);
}

/* free -> content, tlist */
void	delete_token_list(t_tlist *tlist)
{
	t_token	*curr;
	t_token	*temp;

	curr = tlist->head;
	while (curr)
	{
		temp = curr->next;
		free(curr->content);
		free(curr);
		curr = temp;
	}
	free(tlist);
}

static t_token	*new_token(char *chunk)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = NONE;
	token->content = chunk;
	token->next = NULL;
	return (token);
}

void	append_token(t_tlist *tlist, char *chunk)
{
	t_token	*token;

	token = new_token(chunk);
	if (!tlist->count)
	{
		tlist->head = token;
		tlist->tail = token;
		tlist->count++;
	}
	else
	{
		tlist->tail->next = token;
		tlist->tail = token;
		tlist->count++;
	}
}
