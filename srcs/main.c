/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 04:25:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elist	*set_env_list(char **envp)
{
	t_elist	*elist;
	char	**temp;

	elist = create_env_list();
	while (*envp)
	{
		temp = ft_split(*envp++, '=');
		append_env(elist, *temp, *(temp + 1));
	}
	return (elist);
}

void	test_env_list(t_elist *elist)
{
	t_env	*env;
	
	/* print env list */
	print_env_list(elist);

	/* search env by key */
	env = get_env_by_key(elist, "USER");
	if (env)
		print_env(env);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_tlist		*tlist;
	t_elist		*elist;

	if (argc > 1 || argv[1])
		return (EXIT_FAILURE);
	elist = set_env_list(envp);
	// test_env_list(elist);

	/* 추후 분리 */
	while (1)
	{
		tlist = create_token_list();
		line = readline("picoshell$ ");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (check_expression(line))
			continue ;
		tokenize(line, &tlist);
		print_token_list(tlist);
		delete_token_list(tlist);
	}
	return (EXIT_SUCCESS);
}
