/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:11:50 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/25 20:11:50 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char**	parsing(char *str)
{
	char**	token;
	char	open_qut;
	int		start;
	int		end;
	int		state;

	int		i;
	int		idx;

	i = 0;
	idx = 0;
	state = 0;
	open_qut = 0;

	token = (char **)malloc(sizeof(char *) * 100);


	// "          < file | cat " 이런 케이스?
	while (str[i] == ' ')
		i++;
	start = i;
	
	while (str[i])
	{
		if ((str[i] == SQUOTE | str[i] == DQUOTE) && state != -1)
		{
			open_qut = str[i];
			state = -1;
			i++;
			continue;
		}
		if (str[i] == open_qut && state == -1)
		{
			open_qut = 0;
			state = 1;
			i++;
			continue;
		}

		if ((str[i] == '|' || str[i] == '>' || str[i] == '<') && state != -1)
		{
			end = i;
			if (start != end)
			{
				token[idx] = (char *)malloc(sizeof(char) * (end - start + 1));
				ft_strlcpy(token[idx], str + start, end - start + 1);
				idx++;
			}
			if (str[i] != '|' && str[i] == str[i+1]) // >>, << 부분
			{
				token[idx] = (char *)malloc(sizeof(char) * (2 + 1));
				token[idx][0] = str[i];
				token[idx][1] = str[i++];
				token[idx][2] = 0;
				idx++;
			}
			else
			{
				token[idx] = (char *)malloc(sizeof(char) * (1 + 1));
				token[idx][0] = str[i];
				token[idx][1] = 0;
				idx++;
			}
			start = i + 1;
		}
		i++;
	}
	token[idx] = (char *)malloc(sizeof(char) * (ft_strlen(str) - start + 1));
	ft_strlcpy(token[idx], str + start, ft_strlen(str) - start + 1);
	idx++;
	token[idx] = 0;
	return token;
}