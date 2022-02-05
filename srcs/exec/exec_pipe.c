/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:43 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/06 07:03:04 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pipe(t_node *astree, t_elist *elist)
{
	int		pipe_fd[2];
	pid_t	lchild;
	pid_t	rchild;

	pipe(pipe_fd);
	if (pipe(pipe_fd) == -1)
		printf("Error: ");
	if (astree->lnode)
	{
		lchild = fork();
		if (!lchild)
		{
			close(pipe_fd[READ]);
			dup_and_close(pipe_fd[WRITE], STDOUT_FILENO);
			inner_exec(astree->lnode, elist);
			exit(EXIT_SUCCESS);
		}
		waitpid(lchild, NULL, 0);
		close(pipe_fd[WRITE]);
	}
	if (astree->rnode)
	{
		rchild = fork();
		if (!rchild)
		{
			close(pipe_fd[WRITE]);
			dup_and_close(pipe_fd[READ], STDIN_FILENO);
			inner_exec(astree->rnode, elist);
			exit(EXIT_SUCCESS);
		}
		waitpid(rchild, NULL, 0);
		close(pipe_fd[READ]);
	}
}
