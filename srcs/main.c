/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 20:44:36 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_tlist		*tlist;
	t_elist		*elist;
	t_node		*astree;

	(void)argc;
	(void)argv;
	// (void)envp;
	elist = set_env_list(envp);
	// test_env_list(elist);
	// test_trim();

	setting_parent_signal();

	/* 추후 분리 */
	while (1)
	{
		// line = (char *)malloc(sizeof(char) * 100);
		// ft_strcpy(line, "cat < file");
		line = readline("\033[32mpicoshell$ \033[0m");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (is_valid_line(line))
			continue ;
		tlist = create_token_list();
		get_token_list(line, &tlist);
		analize_token_list(tlist);

		astree = get_astree(tlist); 
		exec(astree, elist);
		
		delete_astree(astree);
		delete_token_list(tlist);
		free(line);

		// break ;
	}
	return (EXIT_SUCCESS);
}
