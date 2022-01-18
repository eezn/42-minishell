/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:02:36 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/18 17:27:46 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc syntax.c test.c token.c -I ../../includes/data_structure.h */

#include "../../includes/data_structure.h"

int	main()
{
	t_syntax	*syntax;
	syntax = init_syntax("word1 word2 word3 word4 word5");

	printf("%s\n", syntax->original);
	append_token(syntax, "word1");
	append_token(syntax, "word2");
	append_token(syntax, "word3");
	append_token(syntax, "word4");
	append_token(syntax, "word5");

	t_token	*curr;
	curr = syntax->head;
	while (curr != NULL)
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}
	delete_syntax(syntax);
	return (0);
}
