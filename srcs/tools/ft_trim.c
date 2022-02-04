/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:10:49 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 02:42:44 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 동적할당된 문자열을 대상으로 하는 ltrim 함수 */
char	*ft_ltrim(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = str;
	while (ft_isspace(*ptr))
		ptr++;
	ret = ft_strdup(ptr);
	free(str);
	return (ret);
}

/* 동적할당된 문자열을 대상으로 하는 rtrim 함수 */
char	*ft_rtrim(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = str + ft_strlen(str) - 1;
	while (ft_isspace(*ptr))
		ptr--;
	ret = ft_strldup(str, ptr - str + 1);
	free(str);
	return (ret);
}

/* 동적할당된 문자열을 대상으로 하는 trim 함수 */
char	*ft_trim(char *str)
{
	return (ft_ltrim(ft_rtrim(str)));
}
