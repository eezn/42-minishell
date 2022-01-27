/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:59:30 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/27 19:25:47 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_in_check(char *token, t_elist *elist)
{
	char **tmp;
	tmp = ft_split(token, ' ');
	// if(ft_strnstr("echo", tmp[0], ft_strlen("echo")) != 0)
	// 	built_in_echo(token, tmp);
	if(ft_strnstr("pwd", tmp[0], ft_strlen("pwd")) != 0)
		built_in_pwd(tmp);
	else if(ft_strnstr("cd", tmp[0], ft_strlen("cd")) != 0)
		built_in_cd(token, tmp, elist);
	// else if(ft_strnstr("env", tmp[0], ft_strlen("env")) != 0)
	// 	env(token, env_list);
	// else if(ft_strnstr("export", tmp[0], ft_strlen("export")) != 0)
	// 	export(token, env_list);
	// else if(ft_strnstr("unset", tmp[0], ft_strlen("unset")) != 0)
	// 	unset(token, env_list);
	else if(ft_strnstr("exit", tmp[0], ft_strlen("exit")) != 0)
		exit(1);
	else
		printf("IS NOT BUILT_IN!!\n");
	// free();
	return 0;			
}


static char	*ft_strldup(char *src, int len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}

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

}