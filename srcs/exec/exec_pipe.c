/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:43 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/08 05:34:30 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_pipe(int *fd)
{
	close(fd[WRITE]);
	close(fd[READ]);
}

void	exec_pipe(t_node *astree, t_elist *elist, int *fd)
{
	int		pipe_fd[2];
	pid_t	lchild;
	pid_t	rchild;

	pipe(pipe_fd);
	lchild = fork();
	if (!lchild)
	{
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close_pipe(pipe_fd);
		inner_exec(astree->lnode, elist, fd);
		exit(EXIT_SUCCESS);
	}
	waitpid(lchild, NULL, 0);
	close(pipe_fd[WRITE]);
	rchild = fork();
	if (!rchild)
	{
		dup2(pipe_fd[READ], STDIN_FILENO);
		close_pipe(pipe_fd);
		inner_exec(astree->rnode, elist, fd);
		exit(EXIT_SUCCESS);
	}
	waitpid(rchild, NULL, 0);
	close(pipe_fd[READ]);
}
