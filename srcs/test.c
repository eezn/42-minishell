/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:13:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 19:17:34 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_env_list(t_elist *elist)
{
	t_env	*env;
	
	/* print env list */
	print_env_list(elist); nl();

	/* search env by key */
	env = get_env_by_key(elist, "USER");
	if (env)
		print_env(env);
}

void	test_unset(void)
{
	t_elist	*elist;
	
	elist = create_env_list();
	built_in_export(elist, "A", "1");
	built_in_export(elist, "AB", "23");
	built_in_export(elist, "ABC", "456");
	built_in_export(elist, "_ABC", "789");

	built_in_env(elist); nl(); printf("%zu\n", elist->count);
	
	built_in_unset(elist, "A");
	built_in_unset(elist, "AB");
	built_in_unset(elist, "ABC");
	built_in_unset(elist, "_ABC");

	built_in_env(elist); nl(); printf("%zu\n", elist->count);
	
	print_env(elist->head);
	print_env(elist->tail);
}
