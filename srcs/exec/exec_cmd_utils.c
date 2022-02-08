/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:55:35 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/08 16:25:20 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline char	*ft_envjoin(char const *s1, char const *s2)
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

inline char	**temp_envp(t_elist *elist)
{
	char	**envp;
	int		idx;
	t_env	*curr;

	envp = (char **)malloc(sizeof(char *) * (elist->count + 1));
	if (!envp)
		return (NULL);
	curr = elist->head;
	idx = -1;
	while (++idx < (int)elist->count)
	{
		envp[idx] = ft_envjoin(curr->key, curr->value);
		curr = curr->next;
	}
	envp[idx] = 0;
	return (envp);
}

inline char	**temp_args(t_node *astree)
{
	char	**args;
	int		argc;
	int		idx;
	t_node	*curr;

	argc = 0;
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
	return (args);
}

inline void	clear_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}
