/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:16:33 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/30 17:52:14 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strldup(char *src, int len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}

static int arg_count(char* arg)
{
	char	curr_quote;
	int count;

	count = 1;
	curr_quote = 0;
	while(*arg == ' ')
		arg++;
	while (*arg)
	{
		if (!curr_quote && (*arg == SQUOTE || *arg == DQUOTE))
			curr_quote = *arg;
		else if (curr_quote && *arg == curr_quote)
			curr_quote = 0;
		if(*arg == ' ' && !curr_quote)
		{
			while(*arg == ' ')
				arg++;
			if(*arg)
				count++;
			continue;
		}
		arg++;
	}
	return (count);
}

char** arg_split(char* arg)
{
	char** arg_set;
	int idx;
	char* start;
	char* end;
	char	curr_quote;
	int cnt;

	idx = 0;
	curr_quote = 0;
	cnt = arg_count(arg);
	while (*arg == ' ')
		arg++;
	start = arg;
	arg_set = (char **)malloc(sizeof(char *) * cnt + 1);
	while (*arg)
	{
		if (!curr_quote && (*arg == SQUOTE || *arg == DQUOTE))
			curr_quote = *arg;
		else if (curr_quote && *arg == curr_quote)
			curr_quote = 0;
		if(*arg == ' ' && !curr_quote)
		{
			end = arg - 1;
			while(*arg == ' ')
				arg++;
			if(*arg == 0)
				break;
			arg_set[idx] = ft_strldup(start, end - start + 1);
			start = arg;
			idx++;
			continue;
		}
		arg++;
	}
	while(*(arg -1) == ' ')
		arg--;
	arg_set[idx] = ft_strldup(start, arg - start);
	arg_set[idx + 1] = 0;
	return arg_set;
}