/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:20:49 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 20:26:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str1, char *str2)
{
	ft_putstr_fd("picoshell: ", 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
}
