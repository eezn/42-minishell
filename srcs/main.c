/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/24 15:42:47 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void)
// {
// 	t_tlist	*tlist;

// 	tlist = create_tlist();
// 	append_token(tlist, "abc");
// 	append_token(tlist, "def");
// 	append_token(tlist, "123");
// 	append_token(tlist, "456");
// 	delete_tlist(tlist);
// 	for (int i = 0; i < 10; i++)
// 		printf("%d\n", i);
// 	// loop();
// 	return (0);
// }

int test(t_tlist *tlist)
{
	t_token	*a;

	a = tlist->head;
	printf("--------linked-list-\n");
	while(a->next != 0)
	{
		printf("{ %s }-->--", a->content);
		a = a->next;

	}
	printf("{ %s }\n", a->content);
	return 0;

}

int main(void)
{
    char *str;
	int i;
	// int start;
	// int end;
	char **token;
	t_tlist	*tlist;

	setting_signal();
    while(1)
    {
        str = readline("picoshell$ ");
		if(str==0)
			break;
		if (ft_strlen(str) > 0 && is_empty(str) != -1)
        	add_history(str);
		else
			continue;
		if (qoute_check(str) == -1 || syntax_error_check(str) == -1)
		{
			printf("SYNTAX ERROR\n");
			free(str);
			continue;
		}
		else
			token = parsing(str);
		tlist = create_tlist();

		i = 0;
		while(token[i] != 0)
			append_token(tlist, token[i++]);

		test(tlist);
		printf("----------------str-\n");
		printf("%s\n", str);/* 주소안에 문자열을 출력해보자 */
        free(str);
    }
    return(0);
}
