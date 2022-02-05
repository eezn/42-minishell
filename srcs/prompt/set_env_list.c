/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:58:38 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/06 04:22:03 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_list(char **envp, t_elist **elist)
{
	char	**env;
	char	*ms_shlvl;
	t_env	*shlvl;

	*elist = create_env_list();
	while (*envp)
	{
		env = ft_split(*envp++, '=');
		append_env(*elist, *env, *(env + 1));
	}
	shlvl = get_env_by_key(*elist, "SHLVL");
	ms_shlvl = ft_itoa(ft_atoi(shlvl->value) + 1);
	free(shlvl->value);
	shlvl->value = ms_shlvl;
	append_env(*elist, ft_strdup("MS_DIR"), \
		ft_strdup(get_env_by_key(*elist, "PWD")->value));
}
