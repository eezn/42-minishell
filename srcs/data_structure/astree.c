/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:46:57 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/19 14:59:07 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*new_node(char *content, int type)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->content = content;
	node->root = FALSE;
	node->lnode = NULL;
	node->rnode = NULL;
	return (node);
}

t_node	*set_astree(t_tlist *tlist)
{
	t_node	*astree;
	t_node	*node;
	t_token	*token;

	astree = NULL;
	token = tlist->head;
	while (token)
	{
		node = new_node(token->content, token->type);
		astree = insert_astree(astree, node);
		token = token->next;
	}
	astree->root = TRUE;
	return (astree);
}

void	delete_astree(t_node *astree)
{
	if (astree->lnode != NULL)
		delete_astree(astree->lnode);
	if (astree->rnode != NULL)
		delete_astree(astree->rnode);
	free(astree);
}
