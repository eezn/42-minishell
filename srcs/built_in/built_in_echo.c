/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:17 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/29 18:00:45 by sangchpa         ###   ########.fr       */
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
		i = 2;
		while(token[i] != 0)
		{
			printf("%s",token[i]);
			if ((token[i + 1] != 0))
			printf(" ");
			i++;
		}
	}
	else
	{
		i = 1;
		while(token[i] != 0)
		{
			printf("%s", token[i]);
			if ((token[i + 1] != 0))
			printf(" ");
			i++;
		}
		printf("\n");
	}
}