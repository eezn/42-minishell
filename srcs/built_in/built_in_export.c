/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:22:20 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 19:33:10 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_export(char **token, t_elist *elist)
{
	t_env	*env;
	char	**set;
	int		i;

	if (token[1] == 0)
		printf("export: nothing arguments\n");
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

/*  jin-lee
void	built_in_export(t_elist *elist, char *key, char *value)
{
	t_env	*env;

	env = get_env_by_key(elist, key);
	if (env)
		env->value = value;
	else
		append_env(elist, key, value);
}
*/
