#include "minishell.h"

char** parsing(char* str)
{
	int i;
	int idx;
	int start;
	int end;
	int state;
	char open_qut;
	char** token;

	i = 0;
	idx = 0;
	state = 0;
	open_qut = 0;
	token = (char **)malloc(sizeof(char *) * 100);
	while(str[i] == ' ')
		i++;
	start = i;
	
	// if (str[i] == '<') < file cat 특이케이스
	
	while(str[i])
	{
		if((str[i] == 34 | str[i] == 39) && state != -1)
		{
			open_qut = str[i];
			state = -1;
			i++;
			continue;
		}
		if(str[i] == open_qut && state == -1)
		{
			open_qut = 0;
			state = 1;
			i++;
			continue;
		}
		if((str[i] == '|' || str[i] == '>' || str[i] == '<') && state != -1)
		{
			end = i;
			if(start != end)
			{
				token[idx] = (char *)malloc(sizeof(char) * (end - start + 1));
				ft_strlcpy(token[idx], str + start, end - start + 1);
				idx++;
			}
			if(str[i] != '|' && str[i] == str[i+1] && str[i] != str[i+2])
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