/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:17 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/05 19:32:37 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_loop(char **token, int i)
{
	while (token[++i] != 0)
	{
		printf("%s", token[i]);
		if ((token[i + 1] != 0))
			printf(" ");
	}
}

void	built_in_echo(char **token)
{
	int	i;

	if (token[1] == 0)
		printf("\n");
	else if (ft_strlen(token[1]) == 2 && \
			token[1][0] == '-' && token[1][1] == 'n')
	{
		i = 1;
		print_loop(token, i);
	}
	else
	{
		i = 0;
		print_loop(token, i);
		printf("\n");
	}
}
