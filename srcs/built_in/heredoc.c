#include "minishell.h"

static char	*ft_strjoin_newline(char const *s1, char const *s2)
{
	char		*s;
	char		*ret;
	size_t		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret)
		return (NULL);
	s = ret;
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s++ = '\n';
	*s = 0;
	return (ret);
}

int heredoc(char **token)
{
	char *str;
	char *tmp;
	char *all;

	all = ft_strdup("");
	while(1)
	{
		str = readline("heredoc> ");
		if(str==0)
			break;
		if(ft_strnstr(token[0], str, ft_strlen(token[0])) != 0 && ft_strlen(token[0]) == ft_strlen(str))
		{
			if (token[1] == 0)
			{
				printf("----------------all-\n");
				write(1, all, ft_strlen(all));
				printf("----------------end-\n");
			}
			else
				write(STDIN_FILENO, all, ft_strlen(all));
			free(str);
			free(all);
			return 0;
		}
		tmp = ft_strdup(all);
		free(all);
		all = ft_strjoin_newline(tmp, str);
		free(tmp);
		free(str);
	}
	return 0;
}
