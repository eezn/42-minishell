/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:57:17 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/27 17:03:49 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 추가해야 할것

echo 블라블라 덩어리를 매개변수로 받아서 
"" ''구분해서 스플릿 후 출력하기 
$USER 같이 환경변수 들어왔을 경우 찾아서 값 치환 처리

echo $는 $출력
echo $US는 US라는 환경 변수없으면 아무것도 출력안함
*/

int built_in_echo(char** token, char** tmp)
{
	int i;
	if (token[1] == 0)
		printf("\n");
	// else if (ft_strnstr("-n", token[1], ft_strlen("-n") != 0))
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
	return 0;
}