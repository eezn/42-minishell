#include "minishell.h"

int  qoute_check(char *str)
{
	char open_quote;
	int state;

	state = 0;
	while(*str)
	{
		if((*str == 34 || *str == 39) && state != -1)
		{
			open_quote = *str;
			state = -1;
			str++;
			continue;
		}
		if(*str == open_quote && state == -1)
		{
			open_quote = 0;
			state = 0;
			str++;
			continue;
		}
		str++;
	}
	return state;
}

int is_empty(char *str)
{
	int i;
	i = 0;

	while(str[i])
	{
		if (str[i] != ' ')
			return 1;
		i++;
	}
	return -1;
}

int syntax_error_check(char* str)
{
	int i;
	int state;
	char open_qut;
	
	i = 0;
	state = 0;
	open_qut = 0;
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
		if((str[i] == '|' || str[i] == '>' || str[i] == '<') && str[i+2] != 0)
			if(str[i] == str[i+1] && str[i] == str[i + 2] && state != -1)
				return -1;
		i++;
	}
	return 0;
}