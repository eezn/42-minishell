/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:16:46 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/19 14:41:24 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token_list(t_tlist *tlist)
{
	t_token	*curr;

	horizon_bar('>', RED);
	curr = tlist->head;
	while (curr)
	{
		printf("%s%s%s", PINK, curr->content, EOC);
		printf("%s_%s\n", RED, EOC);
		curr = curr->next;
	}
	horizon_bar('<', RED);
}

/* Token content의 type을 판단 */
static void	inner_analize(t_token *curr, char *content, int prev_type)
{
	if (*content == '|')
		curr->type = PIPE;
	else if (*content == '<')
	{
		curr->type = R_I;
		if (*content == *(content + 1))
			curr->type = R_II;
	}
	else if (*content == '>')
	{
		curr->type = R_O;
		if (*content == *(content + 1))
			curr->type = R_OO;
	}
	else if (ft_strlen(content))
	{
		curr->type = COMMAND;
		if (prev_type == R_I || prev_type == R_O || prev_type == R_OO)
			curr->type = PATH;
		if (prev_type == R_II)
			curr->type = END_SIGN;
	}
}

/* Token content trim 적용, type 판단 -> Token 정보 갱신 */
void	analize_token_list(t_tlist *tlist)
{
	t_token	*curr;
	int		prev_type;

	curr = tlist->head;
	prev_type = NONE;
	while (curr)
	{
		curr->content = ft_trim(curr->content);
		inner_analize(curr, curr->content, prev_type);
		prev_type = curr->type;
		curr = curr->next;
	}
}
