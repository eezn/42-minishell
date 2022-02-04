/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:10:49 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/29 06:52:59 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strldup(char *src, int len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}

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

char	*ft_trim(char *str)
{
	return (ft_ltrim(ft_rtrim(str)));
}
