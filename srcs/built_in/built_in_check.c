/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:59:30 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/02 20:35:49 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_in_check(char **token, t_elist *elist)
{	
	if(ft_strnstr("echo", token[0], ft_strlen("echo")) != 0 && \
		ft_strlen(token[0]) == ft_strlen("echo"))
		built_in_echo(token);
	else if(ft_strnstr("pwd", token[0], ft_strlen("pwd")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("pwd"))
		built_in_pwd(token);
	else if(ft_strnstr("cd", token[0], ft_strlen("cd")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("cd"))
		built_in_cd(token, elist);
	else if(ft_strnstr("env", token[0], ft_strlen("env")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("env"))
		built_in_env(token, elist);
	else if(ft_strnstr("export", token[0], ft_strlen("export")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("export"))
		built_in_export(token, elist);
	else if(ft_strnstr("unset", token[0], ft_strlen("unset")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("unset"))
		built_in_unset(token, elist);
	else if(ft_strnstr("exit", token[0], ft_strlen("exit")) != 0 && \
			ft_strlen(token[0]) == ft_strlen("exit"))
		exit(1);
	else
		return 1;
	return 0;			
}

// static char	*ft_strldup(char *src, int len)
// {
// 	char	*ret;

// 	ret = (char *)malloc(sizeof(char) * (len + 1));
// 	ft_strlcpy(ret, src, len + 1);
// 	return (ret);
// }

int arg_count(char* arg_set)
{

	char	curr_quote;
	int count;

	count = 0;
	curr_quote = 0;
	while (*arg_set)
	{
		if (!curr_quote && (*arg_set == SQUOTE || *arg_set == DQUOTE))
			curr_quote = *arg_set;
		else if (curr_quote && *arg_set == curr_quote)
			curr_quote = 0;
		if(*arg_set == ' ' && !curr_quote)
		{
			if(*arg_set == ' ')
				arg_set++;
			count++;
			continue;
		}
		arg_set++;
	}
	return (count);
}

char** arg_split(char* arg_set, int count)
{
	char** arg;
	int idx;
	char* start;
	char* end;
	char	curr_quote;

	idx = 0;
	curr_quote = 0;
	start = arg_set;
	arg = (char **)malloc(sizeof(char *) * count + 1);
	while (*arg_set)
	{
		if (!curr_quote && (*arg_set == SQUOTE || *arg_set == DQUOTE))
			curr_quote = *arg_set;
		else if (curr_quote && *arg_set == curr_quote)
			curr_quote = 0;
		if(*arg_set == ' ' && !curr_quote)
		{
			if(*arg_set == ' ')
				arg_set++;
			end = arg_set - 1;
			arg[idx] = ft_strldup(start, end - start);
			idx++;
			continue;
		}
		arg_set++;
	}
	return arg;
}
