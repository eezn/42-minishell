/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:17 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/02 20:35:20 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void built_in_echo(char** token)
{
	int i;
	if (token[1] == 0)
		printf("\n");
	else if (ft_strlen(token[1]) == 2 && token[1][0] == '-' && token[1][1] == 'n') //strnstr 안되서 임시 방편
	{
		i = 1;
		while(token[++i] != 0)
		{
			printf("%s",token[i]);
			if ((token[i + 1] != 0))
				printf(" ");
		}
	}
	else
	{
		i = 0;
		while(token[++i] != 0)
		{
			printf("%s", token[i]);
			if ((token[i + 1] != 0))
			printf(" ");
		}
		printf("\n");
	}
}