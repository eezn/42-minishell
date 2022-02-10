/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:20 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/10 04:10:39 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	**convert_list_to_vector(t_elist *elist)
{
	t_env	**env_vector;
	t_env	*curr;
	t_env	*temp;
	int		idx;

	env_vector = (t_env **)malloc(sizeof(t_env *) * elist->count + 1);
	curr = elist->head;
	idx = 0;
	while (curr)
	{
		temp = (t_env *)malloc(sizeof(t_env));
		temp->key = ft_strdup(curr->key);
		temp->value = ft_strdup(curr->value);
		temp->next = NULL;
		env_vector[idx++] = temp;
		curr = curr->next;
	}
	env_vector[idx] = NULL;
	return (env_vector);
}

static t_env	**sort_env_vector(t_env **vc)
{
	t_env	*temp;
	int		i;
	int		j;

	i = 0;
	while (vc[i])
	{
		j = i;
		while (vc[j])
		{
			if (ft_strncmp(vc[i]->key, vc[j]->key, ft_strlen(vc[i]->key)) > 0)
			{
				temp = vc[i];
				vc[i] = vc[j];
				vc[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (vc);
}

static void	print_export_env(t_elist *elist)
{
	t_env	**envv;
	t_env	*curr;
	int		idx;

	envv = sort_env_vector(convert_list_to_vector(elist));
	curr = elist->head;
	idx = -1;
	while (envv[++idx])
	{
		printf("declare -x ");
		printf("%s=\"%s\"\n", envv[idx]->key, envv[idx]->value);
		free(envv[idx]->key);
		free(envv[idx]->value);
		free(envv[idx]);
	}
	free(envv);
}

static void	print_arg_error(t_elist *elist)
{
	printf("export: too many arguments please input like A=B\n");
	elist->exit_status = -1;
}

void	built_in_export(char **token, t_elist *elist)
{
	t_env	*env;
	char	**set;
	int		i;

	if (token[1] == 0)
		print_export_env(elist);
	else if (token[2] != 0)
		print_arg_error(elist);
	else
	{
		set = ft_split(token[1], '=');
		env = get_env_by_key(elist, set[0]);
		if (env)
		{
			free(env->value);
			env->value = ft_strdup(set[1]);
		}
		else
			append_env(elist, ft_strdup(set[0]), ft_strdup(set[1]));
		i = 0;
		while (set[i])
			free(set[i++]);
		free(set);
	}
}
