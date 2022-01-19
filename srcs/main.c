/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/19 16:45:40 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_tlist	*tlist;

	tlist = create_tlist();
	append_token(tlist, "abc");
	append_token(tlist, "def");
	append_token(tlist, "123");
	append_token(tlist, "456");
	delete_tlist(tlist);
	for (int i = 0; i < 10; i++)
		printf("%d\n", i);
	// loop();
	return (0);
}
