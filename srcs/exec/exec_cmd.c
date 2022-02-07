/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 20:21:55 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "errno.h"
#include "string.h"

static char	*ft_pathjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*ret;
	size_t		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret)
		return (NULL);
	s = ret;
	while (*s1)
		*s++ = *s1++;
	*s++ = '/';
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	return (ret);
}

static int	get_exit_status(int status)
{
	int	error_num;

	if ((status & 255) > 0)
		error_num = (status & 255) + 128;
	else
		error_num = status >> 8;
	return (error_num);
}

/* fork()된 자식프로세스, 성공 or 실패시 프로세스 종료 free 필요없음 */
void	inner_exec_cmd(char **args, t_elist *elist)
{
	char	**envp;
	char	**pathv;
	char	*cmd;
	int		idx;
	
	envp = temp_envp(elist);
	execve(args[0], args, envp);
	pathv = ft_split(get_env_by_key(elist, "PATH")->value, ':');
	idx = -1;
	while (pathv[++idx])
	{
		cmd = ft_pathjoin(pathv[idx], args[0]);
		execve(cmd, args, envp);
	}
	print_error(args[0], ": command not found");
	exit(NOT_FOUND);
}

void	exec_cmd(t_node *astree, t_elist *elist)
{
	char	**args;
	int		status;

	status = 0;
	setting_execve_signal();
	args = temp_args(astree);
	filter(args, elist);
	if (check_built_in(args, elist))
	{
		pid_t	pid;
		pid = fork();
		if (!pid)
			inner_exec_cmd(args, elist);
		else
		{
			waitpid(pid, &status, 0);
			elist->exit_status = get_exit_status(status);
		}
	}
	else
		elist->exit_status = 0;
	setting_parent_signal();
	clear_args(args);
}
