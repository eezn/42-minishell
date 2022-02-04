/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:52 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 03:14:16 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elist	*create_env_list(void)
{
	t_elist	*elist;

	elist = (t_elist *)malloc(sizeof(t_elist));
	if (!elist)
		return (NULL);
	elist->head = NULL;
	elist->tail = NULL;
	elist->count = 0;
	return (elist);
}

/* free -> key, value, elist */
void	delete_env_list(t_elist *elist)
{
	t_env	*curr;
	t_env	*temp;

	curr = elist->head;
	while (curr)
	{
		temp = curr->next;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = temp;
	}
	free(elist);
}

static t_env	*new_env(char *key, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = key;
	env->value = value;
	env->next = NULL;
	return (env);
}

/* 중복되는 Key는 고려하지 않음, 초기 envp로 환경변수 리스트를 만들 때만 사용 */
void	append_env(t_elist *elist, char *key, char *value)
{
	t_env	*env;

	env = new_env(key, value);
	if (!elist->count)
	{
		elist->head = env;
		elist->tail = env;
		elist->count++;
	}
	else
	{
		elist->tail->next = env;
		elist->tail = env;
		elist->count++;
	}
}
