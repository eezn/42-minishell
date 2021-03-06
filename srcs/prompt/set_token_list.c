/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:21:28 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/10 13:08:53 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_pv(t_pv *pv, char *str)
{
	pv->start = str;
	pv->curr_quote = 0;
}

static char	*multiple_redirection(char c, int count)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(sizeof(char) * (count + 1));
	while (++i < count)
		ret[i] = c;
	ret[i] = 0;
	return (ret);
}

static void	quote_open(char *str, t_tlist *tlist, t_pv *pv)
{
	if (str != pv->start)
	{
		pv->end = str;
		append_token(tlist, ft_strldup(pv->start, pv->end - pv->start));
		pv->start = str;
	}
	pv->curr_quote = *str;
}

static void	quote_close(char *str, t_tlist *tlist, t_pv *pv)
{
	pv->end = str + 1;
	append_token(tlist, ft_strldup(pv->start, pv->end - pv->start));
	pv->start = str + 1;
	pv->curr_quote = 0;
}

void	set_token_list(char *str, t_tlist **tlist)
{
	t_pv	pv;

	init_pv(&pv, str);
	while (*str)
	{
		if (!pv.curr_quote && (*str == SQUOTE || *str == DQUOTE))
			quote_open(str, *tlist, &pv);
		else if (pv.curr_quote && *str == pv.curr_quote)
			quote_close(str, *tlist, &pv);
		else if (!pv.curr_quote && (*str == '|' || *str == '>' || *str == '<' \
			|| *str == ' '))
		{
			pv.end = str;
			if (pv.start != pv.end)
				append_token(*tlist, ft_strldup(pv.start, pv.end - pv.start));
			if (*str != '|' && *str != ' ' && *str == *(str + 1))
				append_token(*tlist, multiple_redirection(*str++, 2));
			else if (*str == '|' || *str == '<' || *str == '>')
				append_token(*tlist, multiple_redirection(*str, 1));
			pv.start = str + 1;
		}
		str++;
	}
	if (*pv.start)
		append_token(*tlist, ft_strdup(pv.start));
}
