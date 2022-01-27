/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 19:44:28 by sangchpa         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_tlist		*tlist;
	t_elist		*elist;

	if (argc > 1 || argv[1])
		return (EXIT_FAILURE);
	elist = set_env_list(envp);
	// test_env_list(elist);
	// test_unset();

	/* 추후 분리 */
	while (1)
	{
		tlist = create_token_list();
		line = readline("picoshell$ ");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (is_valid_line(line))
			continue ;
		get_token_list(line, &tlist);

		built_in_check(tlist->head->content, elist);

		
		delete_token_list(tlist);
	}
	return (EXIT_SUCCESS);
}
