/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:13:03 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 17:27:26 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rdr_out(t_node *astree, t_elist *elist, int *fd)
{
	int		file_fd;

	if (astree->lnode->type == R_II || astree->lnode->type == R_I \
		|| astree->lnode->type == R_O || astree->lnode->type == R_OO)
	{
		inner_exec(astree->lnode, elist, fd);
		return ;
	}
	printf("%d, %d\n", fd[0], fd[1]);
	file_fd = open_file(elist, astree->rnode->content, R_O);
	if (file_fd == -1)
		return ;
	dup_and_close(file_fd, STDOUT_FILENO);
	inner_exec(astree->lnode, elist, fd);
	restore_fd(fd);
}

static void	rdr_oout(t_node *astree, t_elist *elist, int *fd)
{
	int		file_fd;

	file_fd = open_file(elist, astree->rnode->content, R_OO);
	if (file_fd == -1)
		return ;
	if (astree->lnode->type == R_II || astree->lnode->type == R_I \
		|| astree->lnode->type == R_O || astree->lnode->type == R_OO)
	{
		close(file_fd);
		inner_exec(astree->lnode, elist, fd);
		return ;
	}
	dup_and_close(file_fd, STDOUT_FILENO);
	inner_exec(astree->lnode, elist, fd);
	restore_fd(fd);
}

static void	rdr_in(t_node *astree, t_elist *elist, int *fd)
{
	int		file_fd;

	if (astree->lnode->type == R_II || astree->lnode->type == R_I \
		|| astree->lnode->type == R_O || astree->lnode->type == R_OO)
	{
		inner_exec(astree->lnode, elist, fd);
		return ;
	}
	else
	{
		file_fd = open_file(elist, astree->rnode->content, R_I);
		if (file_fd == -1)
			return ;
		dup_and_close(file_fd, STDIN_FILENO);
		inner_exec(astree->lnode, elist, fd);
		restore_fd(fd);
	}
}

static void	rdr_iin(t_node *astree, t_elist *elist, int *fd)
{
	char	*sign;
	char	*path;
	
	sign = astree->rnode->content;
	path = get_env_by_key(elist, "HEREDOC")->value;
	rl_until_sign(sign, open(path, O_WRONLY | O_CREAT, S_IRWXU));
	dup_and_close(open(path, O_RDONLY, S_IRWXU), STDIN_FILENO);
	inner_exec(astree->lnode, elist, fd);
	restore_fd(fd);
	free(path);
}

void	exec_rdr(t_node *astree, t_elist *elist, int *fd)
{
	
	printf("%d, %d\n", fd[0], fd[1]);
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	printf("%d, %d\n", fd[0], fd[1]);

	if (astree->type == R_O)
		rdr_out(astree, elist, fd);
	else if (astree->type == R_OO)
		rdr_oout(astree, elist, fd);
	else if (astree->type == R_I)
		rdr_in(astree, elist, fd);
	else if (astree->type == R_II)
		rdr_iin(astree, elist, fd);

	restore_fd(fd);
	close(fd[0]);
	close(fd[1]);
}
