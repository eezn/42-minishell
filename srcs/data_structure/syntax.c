/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:13:26 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/17 23:46:50 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"

t_syntax	*init_syntax(char *line)
{
	t_syntax	*syntax;

	syntax = (t_syntax *)malloc(sizeof(t_syntax));
	if (!syntax)
		return (NULL);
	syntax->original = line;
	syntax->head = NULL;
	syntax->tail = NULL;
	syntax->count = 0;
	return (syntax);
}

void	delete_syntax(t_syntax *syntax)
{
	t_token	*curr;
	t_token	*temp;

	if (syntax->count != 0)
	{
		curr = syntax->head;
		temp = syntax->head->next;
		while (curr != NULL)
		{
			free(curr);
			curr = temp;
			if (curr != NULL)
				temp = temp->next;
		}
	}
	free(syntax);
}
