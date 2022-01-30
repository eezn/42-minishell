/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:16:46 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/30 00:48:08 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"
#include "minishell.h"

void	print_token_list(t_tlist *tlist)
{
	t_token	*curr;

	curr = tlist->head;
	while (curr)
	{
		printf("%s", curr->content);
		printf("\033[31m_\033[0m\n");
		curr = curr->next;
	}
}

/* Token content의 type을 판단 */
void	inner_analize(t_token *curr, char *content, int prev_type)
{
	if (*content == '|')
		curr->type = PIPE;
	else if (*content == '<')
	{
		curr->type = R_IN;
		if (*content == *(content + 1))
			curr->type = R_IIN;
	}
	else if (*content == '>')
	{
		curr->type = R_OUT;
		if (*content == *(content + 1))
			curr->type = R_OOUT;
	}
	else if (ft_strlen(content))
	{
		curr->type = CMD_BLOCK;
		if (prev_type == R_IN || prev_type == R_OUT || prev_type == R_OOUT)
			curr->type = PATH;
		if (prev_type == R_IIN)
			curr->type = HERE_DOC;
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
		/* Test >> */
		printf("(%02d)%s", curr->type, curr->content);
		printf("\033[31m_\033[0m\n");
		/* << Test */
		prev_type = curr->type;
		curr = curr->next;
	}
}
