/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:16:37 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/07 20:22:45 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_env(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	interprete_env(char *tmp, char *key, t_elist *elist)
{
	t_env	*ev;
	char	*global_val;

	if (key[0] == '?' && ft_strlen(key) == 1)
	{
		global_val = ft_itoa(elist->exit_status);
		ft_strlcat(tmp, global_val, \
					ft_strlen(tmp) + ft_strlen(global_val) + 1);
		free(global_val);
	}
	else
	{
		ev = get_env_by_key(elist, key);
		if (ev)
			ft_strlcat(tmp, ev->value, \
						ft_strlen(tmp) + ft_strlen(ev->value) + 1);
	}
}

static int	find_env(char *token, char *tmp, t_elist *elist, int start)
{
	int		i;
	int		end;
	char	*key;

	i = start;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] != ' ' && \
			token[i + 1] != 0 && token[i + 1] != '$')
		{
			end = i;
			ft_strlcat(tmp, token + start, ft_strlen(tmp) + end - start + 1);
			i++;
			while (token[i + 1] != ' ' && token[i + 1] != '$' && \
			token[i + 1] != 0 && token[i + 1] != SQUOTE && token[i] != '?')
				i++;
			key = ft_strldup(token + end + 1, i - end);
			interprete_env(tmp, key, elist);
			free(key);
			start = i + 1;
		}
		i++;
	}
	return (start);
}

static char	*env_check(char *token, t_elist *elist)
{
	int		i;
	int		env_end_idx;
	char	*tmp;

	i = 0;
	env_end_idx = 0;
	tmp = ft_calloc(BUFF_SIZE, sizeof(char));
	env_end_idx = find_env(token, tmp, elist, env_end_idx);
	if (env_end_idx != 0)
	{
		if (token[env_end_idx] != 0)
			ft_strlcat(tmp, token + env_end_idx, \
			ft_strlen(tmp) + ft_strlen(token) - env_end_idx + 1);
		free(token);
		token = ft_strdup(tmp);
	}
	free(tmp);
	return (token);
}

void	filter(char **token, t_elist *elist)
{
	int		i;
	char	*tmp;

	i = -1;
	while (token[++i] != 0)
	{
		tmp = ft_strdup(token[i]);
		if (token[i][0] == SQUOTE)
		{
			free(token[i]);
			token[i] = ft_strldup((tmp + 1), ft_strlen(tmp) - 2);
		}
		else
		{			
			if (token[i][0] == DQUOTE)
			{
				free(token[i]);
				token[i] = ft_strldup((tmp + 1), ft_strlen(tmp) - 2);
			}
			if (is_env(token[i]) != 0)
				token[i] = env_check(token[i], elist);
		}
		free(tmp);
	}
}
