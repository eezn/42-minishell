/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:16:46 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 04:21:48 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

void	print_token_list(t_tlist *tlist)
{
	t_token *curr_token;

	curr_token = tlist->head;
	while (curr_token)
	{
		printf("%s\n", curr_token->content);
		curr_token = curr_token->next;
	}
}
