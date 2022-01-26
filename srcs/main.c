/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 20:15:33 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int argc, char **argv, char **envp)
int main(void)
{
	char		*line;
	t_tlist		*token_list;

	while (1)
	{
		token_list = create_tlist();
		line = readline("picoshell$ ");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (check_expression(line))
			continue ;
		tokenize(line, &token_list);
		print_tlist(token_list);
		delete_tlist(token_list);
	}
	return (EXIT_SUCCESS);
}
