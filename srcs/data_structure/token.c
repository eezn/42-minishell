/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:26:19 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/17 23:37:34 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"

static t_token	*new_token(char *chunk)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = chunk;
	token->next = NULL;
	return (token);
}

void	append_token(t_syntax *syntax, char *chunk)
{
	t_token	*token;

	token = new_token(chunk);
	if (!syntax->count)
	{
		syntax->head = token;
		syntax->tail = token;
		syntax->count++;
	}
	else
	{
		syntax->tail->next = token;
		syntax->tail = token;
		syntax->count++;
	}
}
