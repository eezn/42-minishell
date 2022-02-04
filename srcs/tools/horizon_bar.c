/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizon_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:22:00 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 04:59:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	horizon_bar(char c, char *color)
{
	struct winsize	size;
	int				idx;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return ;
	idx = 0;
	ft_putstr_fd(color, STDOUT_FILENO);
	while (idx++ < size.ws_col)
		ft_putchar_fd(c, STDOUT_FILENO);
	ft_putendl_fd(EOC, STDOUT_FILENO);
}
