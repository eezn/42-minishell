/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:59:04 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/08 17:38:10 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tlist	*token(t_tlist *tlist, char *line)
{
	tlist = create_token_list();
	set_token_list(line, &tlist);
	analize_token_list(tlist);
	return (tlist);
}

static void	clear(t_tlist *tlist, t_elist *elist, char *line)
{
	delete_token_list(tlist);
	unlink(get_env_by_key(elist, "HEREDOC")->value);
	free(line);
}

/* main loop */
void	main_loop(char **envp)
{
	t_elist	*elist;
	t_tlist	*tlist;
	char	*line;

	set_env_list(envp, &elist);
	setting_parent_signal();
	while (1)
	{
		line = readline(PROMPT);
		if (!line)
			return ;
		if (line_history(line))
			continue ;
		if (line_syntax(line))
			continue ;
		tlist = token(tlist, line);
		exec(tlist, elist);
		clear(tlist, elist, line);
	}
	delete_env_list(elist);
}

/* main without loop */
void	main_debug(char **envp, char *test_line)
{
	t_elist	*elist;
	t_tlist	*tlist;
	char	*line;

	set_env_list(envp, &elist);
	setting_parent_signal();
	line = (char *)malloc(sizeof(char) * (ft_strlen(test_line) + 1));
	if (!line)
		return ;
	ft_strcpy(line, test_line);
	if (line_history(line))
		return ;
	if (line_syntax(line))
		return ;
	tlist = NULL;
	tlist = token(tlist, line);
	exec(tlist, elist);
	clear(tlist, elist, line);
}
