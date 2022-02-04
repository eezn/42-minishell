/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:11:44 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 02:33:46 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_not_space(char *str)
{
	while (*str)
		if (!ft_isspace(*str++))
			return (1);
	return (0);
}

int	line_history(char *str)
{
	if (ft_strlen(str) > 0 && is_not_space(str))
		add_history(str);
	else
	{
		free(str);
		return (1);
	}
	return (0);
}
