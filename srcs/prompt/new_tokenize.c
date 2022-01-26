/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:21:28 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 17:26:52 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *set_redirect_str(char c, int size)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		ret[i] = c;
	ret[i] = 0;
	return (ret);
}

char	*ft_strldup(char *src, int len)
{
	char *ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}

void	tokenize(char *str, t_tlist *token_list)
{
	char	*start;
	char	*end;
	char	curr_quote;
	
	/* temp */
	append_token(token_list, "123");
	printf("%s$\n", str);
	/* temp */

	curr_quote = 0;
	start = str;
	while (*str)
	{
		if (!curr_quote && (*str == SQUOTE || *str == DQUOTE))
			curr_quote = *str;
		else if (curr_quote && *str == curr_quote)
			curr_quote = 0;
		if (!curr_quote && (*str == '|' || *str == '>' || *str == '<'))
		{
			end = str;
			if (start != end)
				printf("%s\n", ft_strldup(start, end - start));
			if (*str != '|' && *str == *(str + 1))	// >>, <<
			{
				printf("%s\n", set_redirect_str(*str, 2));
				start = str + 2;
				str++;
			}
			else
				printf("%s\n", set_redirect_str(*str, 1));
			start = str + 1;
		}
		str++;
	}
	printf("%s\n", ft_strdup(start));
}


