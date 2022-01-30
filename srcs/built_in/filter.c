/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:16:37 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/30 17:55:47 by sangchpa         ###   ########.fr       */
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

////$? env에 세팅해 줘야 한다

static int is_env(char* token)
{
	int i;
	i = 0;

	while(token[i])
	{
		if(token[i] == '$' && token[i + 1] != ' ' && token[i + 1] != 0)
			return 1;
		i++;
	}
	return 0;
}


static char* env_check(char* token, t_elist *elist)
{
	int i;
	int start;
	int end;
	char *tmp;
	char *key;
	t_env	*env;

	i = 0;
	start = 0;
	tmp = ft_calloc(1024, sizeof(char));
	while(token[i])
	{
		if(token[i] == '$' && token[i + 1] != ' ' && token[i + 1] != 0)
		{
			end = i;
			ft_strlcat(tmp, token + start, ft_strlen(tmp) + end - start + 1);
			while(token[i + 1] != ' ' && token[i + 1] != '$' && token[i + 1] != 0)
				i++;
			key = ft_strldup(token + end + 1, i - end);
			env = get_env_by_key(elist, key);
			if(env)
				ft_strlcat(tmp, env->value, ft_strlen(tmp) + ft_strlen(env->value) + 1);
			free(key);
			start = i + 1;
		}
		i++;
	}
	if (start != 0)
	{
		if (token[start] != 0)
			ft_strlcat(tmp, token + start, ft_strlen(tmp) + ft_strlen(token) - start + 1);
		free(token);
		token = ft_strdup(tmp);
	}
	free(tmp);
	return token;
}


char** filter(char **token, t_elist *elist)
{
	int i;
	char* tmp;

	i = 0;
	while(token[i] != 0)
	{
		tmp = ft_strdup(token[i]);
		if(token[i][0] == SQUOTE)
		{
			free(token[i]);
			token[i] = ft_strldup((tmp+1), ft_strlen(tmp)-2);
		}
		else
		{
			
			if(token[i][0] == DQUOTE)
			{
				free(token[i]);
				token[i] = ft_strldup((tmp+1), ft_strlen(tmp)-2);
			}
			if(is_env(token[i]))
			{
				token[i] = env_check(token[i], elist);
			}
		}
		free(tmp);
		i++;
		// printf("%d = ----------end-\n", i);
	}
	return token;
}