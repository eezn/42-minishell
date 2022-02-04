/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:21:28 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 02:22:32 by jin-lee          ###   ########.fr       */
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

void	set_token_list(char *str, t_tlist **tlist)
{
	t_pv	pv;

	init_pv(&pv, str);
	while (*str)
	{
		if (!pv.curr_quote && (*str == SQUOTE || *str == DQUOTE))
			pv.curr_quote = *str;
		else if (pv.curr_quote && *str == pv.curr_quote)
			pv.curr_quote = 0;
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
	append_token(*tlist, ft_strdup(pv.start));
}
