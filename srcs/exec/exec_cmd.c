/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 00:25:16 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_exit_result(int stat)
{
	int	result;

	if ((stat & 255) > 0)
		result = (stat & 255) + 128;
	else
		result = stat >> 8;
	return (result);
}

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
	write(2, PROMPT, 21);
	write(2, args[0], ft_strlen(args[0]));
	write(2, ": command not found\n", 20);
	exit(127);
}

void	exec_cmd(t_node *astree, t_elist *elist)
{
	char	**args;
	int		status;
	pid_t	pid;

	status = 0;
	setting_execve_signal();
	args = temp_args(astree);
	filter(args, elist);
	if (check_built_in(args, elist))
	{
		pid = fork();
		if (!pid)
			inner_exec_cmd(args, elist);
		else
		{
			waitpid(pid, &status, 0);
			elist->exit_status = get_exit_result(status);
		}
	}
	else
		elist->exit_status = 0;
	setting_parent_signal();
	clear_args(args);
}
