/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:14:33 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 23:18:34 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_syntax(t_node *astree)
{
	if (astree == NULL)
		return (TRUE);
	if (astree->type == R_I || astree->type == R_II \
		|| astree->type == R_O || astree->type == R_OO || astree->type == PIPE)
		if (astree->lnode == NULL)
			return (FALSE);
	if (!check_syntax(astree->lnode) || !check_syntax(astree->rnode))
		return (FALSE); 
	return (TRUE);
}

void	inner_exec(t_node *astree, t_elist *elist)
{
	if (astree->type == COMMAND)
		exec_cmd(astree, elist);
	else if (astree->type == PIPE)
		exec_pipe(astree, elist);
	else if (astree->type == R_I || astree->type == R_II \
		|| astree->type == R_O || astree->type == R_OO)
		exec_rdr(astree, elist);
}

void	exec(t_tlist *tlist, t_elist *elist)
{
	t_node	*astree;
	
	astree = set_astree(tlist); 
	if (!check_syntax(astree))
		printf("Syntax Error\n");
	else
		inner_exec(astree, elist);
	delete_astree(astree);
}
