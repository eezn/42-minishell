/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 23:14:22 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* fork()된 자식프로세스, 성공 or 실패시 프로세스 종료 free 필요없음 */
void	inner_exec_cmd(char **args, t_elist *elist)
{
	char	**envp;
	char	**pathv;
	char	*temp;
	char	*cmd;
	int		idx;

	envp = temp_envp(elist);
	execve(args[0], args, envp);
	pathv = ft_split(get_env_by_key(elist, "PATH")->value, ':');
	idx = -1;
	while (pathv[++idx])
	{
		temp = ft_strjoin(pathv[idx], "/");
		cmd = ft_strjoin(temp, args[0]);
		free(temp);
		execve(cmd, args, envp);
	}
	printf("Error: exec\n");
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_node *astree, t_elist *elist)
{
	char	**args;
	pid_t	pid;

	setting_execve_signal();
	args = temp_args(astree);
	filter(args, elist);
	if (check_built_in(args, elist))
	{
		pid = fork();
		if (!pid)
			inner_exec_cmd(args, elist);
		else
			waitpid(pid, NULL, 0);
	}
	setting_parent_signal();
	clear_args(args);
}
