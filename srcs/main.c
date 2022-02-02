/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/02 20:52:04 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elist	*set_env_list(char **envp)
{
	t_elist	*elist;
	char	**temp;

	elist = create_env_list();
	while (*envp)
	{
		temp = ft_split(*envp++, '=');
		append_env(elist, *temp, *(temp + 1));
	}
	return (elist);
}

void line_free(char* line, char**token)
{
	int i;
	i = 0;

	while(token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
	free(line);
	return ((void)0);
}


void print_test(char** token)
{
	int i;
	i = 0;

	while(token[i])
	{
		printf("|%d = %s|\n",i, token[i]);
		i++;
	}
}

static void	execute(char **token, t_elist *elist)
{
	t_env	*env;
	char	**pathv;
	char	*temp;
	char	*path;
	int		i;

	i = 0;
	env = get_env_by_key(elist, "PATH");
	pathv = ft_split(env->value + 5, ':');
	while (pathv[i])
	{
		temp = ft_strjoin(pathv[i], "/");
		path = ft_strjoin(temp, token[0]);
		free(temp);
		if (access(path, F_OK) == 0)
		{
			execve(path, token, NULL);
			perror(token[0]);
		}
		free(path);
		i++;
	}
}


int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_tlist		*tlist;
	
	t_elist		*elist;
	char** token;

	pid_t	pid;

	if (argc > 1 || argv[1])
		return (EXIT_FAILURE);
	setting_signal();
	elist = set_env_list(envp);
	// test_env_list(elist);
	// test_unset();


	/* 추후 분리 */
	while (1)
	{
		tlist = create_token_list();
		line = readline("picoshell$ ");
		if (!line)
			return (EXIT_FAILURE);
		if (record_history(line))
			continue ;
		if (is_valid_line(line))
			continue ;
		get_token_list(line, &tlist);

		
		token = arg_split(tlist->head->content);
		filter(token, elist);
		if (built_in_check(token, elist) > 0)
		{
			pid = fork();
			if (!pid)
			{
				execute(token, elist);
				perror(token[0]);
				return 0;
			}
			else
				wait(&pid);
		}
		// heredoc(token);

		line_free(line, token);
		delete_token_list(tlist);
	}
	return (EXIT_SUCCESS);
}
