/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:56:44 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/04 19:13:53 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cd_arg_check(char** tmp, t_elist *elist, t_env *env_pwd, t_env *env_oldpwd)
{
	t_env	*env_home;
	char *tmp_path;

	env_home = get_env_by_key(elist, "HOME");	
	if (tmp[1] != 0 && tmp[2] != 0)
		return (printf("cd: too many arguments\n"));
	else if(tmp[1] == 0 || (tmp[1][0] == '~' && ft_strlen(tmp[1]) == 1))
	{
		free(env_oldpwd->value);
		env_oldpwd->value = ft_strdup(env_pwd->value);
		chdir(env_home->value);
		free(env_pwd->value);
		env_pwd->value = ft_strdup(env_home->value);
	}
	else if (tmp[1][0] == '-' && ft_strlen(tmp[1]) == 1)
	{
		tmp_path = ft_strdup(env_oldpwd->value);
		chdir(env_oldpwd->value);
		free(env_oldpwd->value);
		env_oldpwd->value =ft_strdup(env_pwd->value);
		free(env_pwd->value);
		env_pwd->value = ft_strdup(tmp_path);
		free(tmp_path);
	}
	else
		return 0;
	return 1;
}

int built_in_cd(char** tmp, t_elist	* elist)
{
	t_env	*env_pwd;
	t_env	*env_oldpwd;
	char cwd[1024];

	env_pwd = get_env_by_key(elist, "PWD");
	env_oldpwd = get_env_by_key(elist, "OLDPWD");
	
	if (cd_arg_check(tmp, elist, env_pwd, env_oldpwd) > 0)
		return 0;
	if (chdir(tmp[1]) == -1)
		printf("IS NOT FOUND\n");
	else
	{
		free(env_oldpwd->value);
		env_oldpwd->value = ft_strdup(env_pwd->value);
		getcwd(cwd, sizeof(cwd));
		free(env_pwd->value);
		env_pwd->value = ft_strdup(cwd);
	}
	return 0;
}