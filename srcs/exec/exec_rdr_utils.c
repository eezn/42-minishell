/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 06:28:30 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/08 07:03:57 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file(t_elist *elist, char *path, int type)
{
	int	file_fd;

	file_fd = -1;
	if (type == R_O)
		file_fd = open(path, O_WRONLY | O_CREAT, S_IRWXU);
	else if (type == R_OO)
		file_fd = open(path, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	else if (type == R_I)
		file_fd = open(path, O_RDONLY, S_IRWXU);
	if (file_fd == -1)
	{
		print_error(path, ": No such file or directory");
		elist->exit_status = 1;
	}
	return (file_fd);
}

void	dup_and_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	restore_fd(int	*fd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

/* 종료단어가 나오기 전까지 멀티 라인을 fd에 기록 */
void	rl_until_sign(char *sign, int fd)
{
	char	*line;

	line = readline("> ");
	while (ft_strncmp(line, sign, ft_strlen(sign)) \
		|| ft_strlen(line) != ft_strlen(sign))
	{	
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(fd);
}
