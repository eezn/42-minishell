/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 21:11:44 by jin-lee          ###   ########.fr       */
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
			args[idx++] = ft_strdup(curr->content);
			curr = curr->rnode;
		}
		args[idx] = NULL;
	}
	else
	{
		// 합칠 수 있으면 합치기
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = ft_strdup(astree->content);
		args[1] = NULL;
	}
	// printf("%d\n", argc);
	// idx = -1;
	// while (args[++idx])
	// 	printf("args[%d]: %s\n", idx, args[idx]);
	return (args);
}

static char	*ft_envjoin(char const *s1, char const *s2)
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
	*s++ = '=';
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	return (ret);
}

char	**get_envp(t_elist *elist)
{
	int		idx;
	t_env	*curr;
	char	**envp;

	idx = 0;
	curr = elist->head;
	envp = (char **)malloc(sizeof(char *) * (elist->count + 1));
	while (idx < (int)elist->count)
	{
		envp[idx++] = ft_envjoin(curr->key, curr->value);
		curr = curr->next;
	}
	// idx = -1;
	// while (envp[++idx])
	// 	printf("envp[%02d]: %s\n", idx, envp[idx]);
	return (envp);
}

void	inner_exec_cmd(char **args, t_elist *elist)
{
	char	**envp;
	char	**pathv;
	char	*cmd;
	char	*temp;
	int		idx;

	envp = get_envp(elist);
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
	// 자식프로세스에서 실행이 안될 경우 에러 출력하고, 자식프로세스 종료
	printf("error: exec\n");
	exit(EXIT_FAILURE);
}


void	exec_cmd(t_node *astree, t_elist *elist)
{
	char	**args;
	pid_t	pid;

	args = get_args(astree);
	filter(args, elist);

	if (built_in_check(args, elist))
	{
		pid = fork();
		printf("%d\n", getpid());
		if (!pid)
		{
			setting_child_signal();
			inner_exec_cmd(args, elist); // fork()
		}
		else
			wait(NULL);
	}
	int i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);

	
	printf("%d\n", getpid());
}
