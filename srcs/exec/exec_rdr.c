/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:13:03 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/06 01:48:40 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_rdr(t_node *astree, t_elist *elist)
{
	int	fd[2];
	int	file_fd;

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	if (astree->type == R_O)
	{
		file_fd = open(astree->rnode->content, O_WRONLY | O_CREAT, S_IRWXU);
		dup2(file_fd, STDOUT_FILENO);
		close(file_fd);
		inner_exec(astree->lnode, elist);
		dup2(fd[1], STDOUT_FILENO); // 원상복구
	}
	else if (astree->type == R_OO)
	{
		file_fd = open(astree->rnode->content, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
		dup2(file_fd, STDOUT_FILENO);
		close(file_fd);
		inner_exec(astree->lnode, elist);
		dup2(fd[1], STDOUT_FILENO); // 원상복구
	}
	else if (astree->type == R_I)
	{
		file_fd = open(astree->rnode->content, O_RDONLY, S_IRWXU);
		dup2(file_fd, STDIN_FILENO);
		close(file_fd);
		inner_exec(astree->lnode, elist);
		dup2(fd[0], STDIN_FILENO); // 원상복구
	}
	else if (astree->type == R_II) // heredoc
		pass();
}
