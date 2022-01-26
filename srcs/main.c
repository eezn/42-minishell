/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 03:05:45 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	test_tlist(void)
// {
// 	t_tlist	*tlist;

// 	tlist = create_tlist();
// 	append_token(tlist, "abc");
// 	append_token(tlist, "def");
// 	append_token(tlist, "123");
// 	append_token(tlist, "456");
// 	delete_tlist(tlist);
// }

/* ************************************************************************** */

// int	main(int argc, char **argv, char **envp)
int main(void)
{
	char		*str;
	t_tlist		*token_list;

	token_list = create_tlist();
	while (1)
	{
		str = readline("picoshell$ ");
		if (!str)
			return (EXIT_FAILURE);

		// 입력된 라인이 널 문자열 또는 공백 문자열인지 검사, 유효할 경우 명령어 히스토리에 반영
		if (record_history(str))
			continue ;
		if (check_expression(str))
			continue ;

		// 입력된 라인을 파싱하고, 토큰화해서 token_list를 반환
		// token_list = parsing(str); // tokenizing(str);
		tokenize(str, token_list);
	}
	return (EXIT_SUCCESS);
}
