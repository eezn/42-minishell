/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:20 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/09 02:21:01 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static void	print_export_env(t_elist *elist)
{
	t_env	*curr;

	curr = elist->head;
	while (curr)
	{
		printf("declare -x ");
		print_env(curr);
		curr = curr->next;
	}
}

void	built_in_export(char **token, t_elist *elist)
{
	t_env	*env;
	char	**set;
	int		i;

	if (token[1] == 0)
		print_export_env(elist);
	else if (token[2] != 0)
		printf("export: too many arguments\n");
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
		while (set[i++])
			free(set[i]);
		free(set);
	}
}
