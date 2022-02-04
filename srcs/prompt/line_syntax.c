/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:11:42 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 04:59:03 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_open_quote(char *str)
{
	char	curr_quote;

	curr_quote = 0;
	while (*str)
	{
		if (!curr_quote && (*str == SQUOTE || *str == DQUOTE))
			curr_quote = *str;
		else if (curr_quote && *str == curr_quote)
			curr_quote = 0;
		str++;
	}
	return (curr_quote);
}

static int	is_triple(char *str)
{
	char	curr_quote;

	curr_quote = 0;
	while (*str)
	{
		if (!curr_quote && (*str == SQUOTE || *str == DQUOTE))
			curr_quote = *str;
		else if (curr_quote && *str == curr_quote)
			curr_quote = 0;
		else if ((*str == '|' || *str == '>' || *str == '<') && *(str + 2) != 0)
			if (!curr_quote && *str == *(str + 1) && *str == *(str + 2))
				return (1);
		str++;
	}
	return (0);
}

/* 입력된 명령어 라인이 유효한지 검사, 유효하지 않으면 에러메세지 출력 */
int	line_syntax(char *str)
{
	int	state;

	state = is_open_quote(str);
	state = is_triple(str);
	if (state)
	{
		printf("Undifined Syntax\n");
		free(str);
		return (1);
	}
	return (0);
}
