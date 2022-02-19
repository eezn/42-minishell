/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_astree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:24:52 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/19 14:42:17 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*insert_root_rdr(t_node *root, t_node *insert)
{
	if (insert->type == END_SIGN || insert->type == PATH)
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
	return (NULL);
}

static t_node	*insert_root_cmd(t_node *root, t_node *insert)
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
	return (NULL);
}

static t_node	*insert_root_pipe(t_node *root, t_node *insert)
{
	if (insert->type == END_SIGN || insert->type == PATH)
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
	return (NULL);
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
