/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 16:25:56 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_args(t_node *astree)
{
	t_node	*curr;
	int		idx;
	int		argc;
	char	**args;

	argc = 0;
	args = NULL;
	if (astree->rnode)
	{
		curr = astree;
		while (curr)
		{
			argc++;
			curr = curr->rnode;
		}
		args = (char **)malloc(sizeof(char *) * (argc + 1));
		idx = 0;
		curr = astree;
		while (curr)
		{
			args[idx++] = curr->content;
			curr = curr->rnode;
		}
		args[idx] = NULL;
	}
	else
	{
		// 합칠 수 있으면 합치기
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = astree->content;
		args[1] = NULL;
	}
	// printf("%d\n", argc);
	// idx = -1;
	// while (args[++idx])
	// 	printf("args[%d]: %s\n", idx, args[idx]);
	return (args);
}

char	**get_envp(t_elist *elist)
{
	int		idx;
	t_env	*curr;
	char	**envp;
	char	*temp;

	idx = 0;
	curr = elist->head;
	envp = (char **)malloc(sizeof(char *) * (elist->count + 1));
	while (idx < (int)elist->count)
	{
		temp = ft_strdup(curr->key);
		temp = ft_strjoin(temp, "=");
		temp = ft_strjoin(temp, curr->value);
		// ft_strjoin 중간 부산물 free 필요
		envp[idx++] = temp;
		curr = curr->next;
	}
	// idx = -1;
	// while (envp[++idx])
	// 	printf("envp[%02d]: %s\n", idx, envp[idx]);
	return (envp);
}

void	exec_cmd(t_node *astree, t_elist *elist)
{
	char	**args;
	char	**envp;
	char	*cmd;
	char	**pathv;
	int		idx;
	char	*temp;

	args = get_args(astree);
	envp = get_envp(elist);
	// printf("%s\n", get_env_by_key(elist, "PATH")->value);
	pathv = ft_split(get_env_by_key(elist, "PATH")->value, ':');
	idx = -1;
	while (pathv[++idx])
	{
		temp = ft_strjoin(pathv[idx], "/");
		cmd = ft_strjoin(temp, args[0]);
		free(temp);
		if (access(cmd, F_OK) == 0)
			if (execve(cmd, args, envp) == -1)
				printf("exec");
	}
	// 실행 후 minishell 종료 안되게 하려면 fork 해서 자식프로세스에서 execve 실행해야함
}
