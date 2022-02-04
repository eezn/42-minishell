/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:46:57 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/03 14:58:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

t_node	*new_node(char *content, int type)
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

t_node	*insert_root_rdr(t_node *root, t_node *insert)
{
	if (insert->type == HEREDOC || insert->type == PATH)
	{
		if (root->rnode == NULL)
			root->rnode = insert;
		else
			root->lnode = insert_astree(root->lnode, insert);
		return (root);
	}
	else if (insert->type == COMMAND || insert->type == R_I \
		|| insert->type == R_II || insert->type == R_O || insert->type == R_OO)
	{
		root->lnode = insert_astree(root->lnode, insert);
		return (root);
	}
	else if (insert->type == PIPE)
	{
		insert->lnode = root;
		return (insert);
	}
	return (root);	// else 부분 확인 필요
}

t_node	*insert_root_cmd(t_node *root, t_node *insert)
{
	if (root->type == insert->type)
	{
		root->rnode = insert_astree(root->rnode, insert);
		return (root);
	}
	else if (insert->type == PIPE || insert->type == R_I \
		|| insert->type == R_II || insert->type == R_O || insert->type == R_OO)
	{
		insert->lnode = root;
		return (insert);
	}
	return (root);	// else 부분 확인 필요
}

t_node	*insert_root_pipe(t_node *root, t_node *insert)
{
	if (insert->type == HEREDOC || insert->type == PATH)
	{
		if (root->rnode == NULL)
			root->rnode = insert;
		else
			root->rnode = insert_astree(root->rnode, insert);
		return (root);
	}
	else if (insert->type == COMMAND || insert->type == R_I \
		|| insert->type == R_II || insert->type == R_O || insert->type == R_OO)
	{
		root->rnode = insert_astree(root->rnode, insert);
		return (root);
	}
	else if (insert->type == PIPE)
	{
		insert->lnode = root;
		return (insert);
	}
	return (root);	// else 부분 확인 필요
}

t_node	*insert_astree(t_node *root, t_node *insert)
{
	if (root == NULL)
		return (insert);
	if (root->type == R_I || root->type == R_II \
		|| root->type == R_O || root->type == R_OO)
		root = insert_root_rdr(root, insert);
	else if (root->type == COMMAND)
		root = insert_root_cmd(root, insert);
	else if (root->type == PIPE)
		root = insert_root_pipe(root, insert);
	return (root);
}

t_node	*get_astree(t_tlist *tlist)
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
