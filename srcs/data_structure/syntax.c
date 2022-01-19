/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:41:19 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/19 16:33:18 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

/* 추후 tree 사용할때 바뀔 수 있음 */
t_syntax	*init_syntax(char *line)
{
	t_syntax	*syntax;

	syntax = (t_syntax *)malloc(sizeof(t_syntax));
	if (!syntax)
		return (NULL);
	syntax->original = line;
	syntax->delimeter_tokens = create_tlist();
	syntax->command_tokens = create_tlist();
	// syntax->count = 0;
	return (syntax);
}
