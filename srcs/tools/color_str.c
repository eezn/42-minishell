/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:55:02 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 04:08:55 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	color_str(char *str, char *color)
{
	ft_putstr_fd(color, STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putendl_fd(EOC, STDOUT_FILENO);
}
