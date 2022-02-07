/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:14:33 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 21:29:55 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_syntax(t_node *astree)
{
	if (astree == NULL)
		return (TRUE);
	if (astree->type == R_I || astree->type == R_II \
		|| astree->type == R_O || astree->type == R_OO || astree->type == PIPE)
		if (astree->rnode == NULL)
			return (FALSE);
	if (astree->type == COMMAND && astree->lnode != NULL)
		return (FALSE);
	if (!check_syntax(astree->lnode) || !check_syntax(astree->rnode))
		return (FALSE); 
	return (TRUE);
}

void	inner_exec(t_node *astree, t_elist *elist, int *fd)
{
	if (astree->type == COMMAND)
		exec_cmd(astree, elist);
	else if (astree->type == PIPE)
		exec_pipe(astree, elist, fd);
	else if (astree->type == R_I || astree->type == R_II \
		|| astree->type == R_O || astree->type == R_OO)
		exec_rdr(astree, elist, fd);
}

void	exec(t_tlist *tlist, t_elist *elist)
{
	t_node	*astree;
	int		fd[2];
	
	fd[0] = dup(STDIN_FILENO);	// 표준입력 백업
	fd[1] = dup(STDOUT_FILENO);	// 표준출력 백업
	
	astree = set_astree(tlist); 
	if (!check_syntax(astree))
		printf("Syntax Error\n");
	else
		inner_exec(astree, elist, fd);

	delete_astree(astree);
	restore_fd(fd);			// 표준입출력 복구
}
