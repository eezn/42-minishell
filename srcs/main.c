/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/30 03:28:12 by jin-lee          ###   ########.fr       */
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
	// test_trim();

	/* 추후 분리 */
	while (1)
	{
		tlist = create_token_list();
		line = readline("\033[32mpicoshell$ \033[0m");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (is_valid_line(line))
			continue ;
		get_token_list(line, &tlist);
		// print_token_list(tlist); nl();
		analize_token_list(tlist);
		// built_in_check(tlist->head->content, elist);
		delete_token_list(tlist);
	}
	return (EXIT_SUCCESS);
}
