/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:26:19 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 20:14:57 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

static t_token	*new_token(char *chunk)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = chunk;
	token->next = NULL;
	return (token);
}

/* ************************************************************************** */

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

t_tlist	*create_tlist(void)
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

void	delete_tlist(t_tlist *tlist)
{
	t_token	*curr;
	t_token	*temp;

	if (tlist->count)
	{
		curr = tlist->head;
		temp = tlist->head->next;
		while (curr)
		{
			// printf("%p, %s\n", curr, curr->content);
			free(curr);
			curr = temp;
			if (curr)
				temp = temp->next;
		}
	}
	free(tlist);
}

void	print_tlist(t_tlist *tlist)
{
		t_token *curr_token;

		curr_token = tlist->head;
		while (curr_token)
		{
			printf("%s\n", curr_token->content);
			curr_token = curr_token->next;
		}
}
