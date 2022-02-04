/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:58:38 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 18:59:46 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elist	*set_env_list(char **envp)
{
	t_elist	*elist;
	char	**temp;
	char	*shlvl_update;
	t_env	*shlvl;

	elist = create_env_list();
	while (*envp)
	{
		temp = ft_split(*envp++, '=');
		append_env(elist, *temp, *(temp + 1));
	}
	shlvl = get_env_by_key(elist, "SHLVL");
	shlvl_update = ft_itoa(ft_atoi(shlvl->value) + 1);
	free(shlvl->value);
	shlvl->value = shlvl_update;
	return (elist);
}
