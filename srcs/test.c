/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:13:06 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 19:21:58 by jin-lee          ###   ########.fr       */
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

void	test_trim(void)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * 30);
	ft_strcpy(str, "       123       ");
	// printf("%s<-\n", ft_rtrim(str));
	// printf("%s<-\n", ft_ltrim(str));
	printf("%s<-\n", ft_trim(str));
}
