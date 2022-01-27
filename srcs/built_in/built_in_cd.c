/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:56:44 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/27 20:13:20 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cd_arg_check(char** tmp, t_elist *elist, t_env *env_pwd, t_env *env_oldpwd)
{
	t_env	*env_home;
	char *tmp_path;

	env_home = get_env_by_key(elist, "HOME");
	if(tmp[1] == 0 || (tmp[1][0] == '~' && ft_strlen(tmp[1]) == 1))
	{
		env_oldpwd->value = env_pwd->value;
		chdir(env_home->value);
		env_pwd->value = env_home->value;
	}
	if (tmp[2] != 0)
		printf("cd: too many arguments\n");
	if (tmp[1][0] == '-' && ft_strlen(tmp[1]) == 1)
	{
		tmp_path = env_oldpwd->value;
		chdir(env_oldpwd->value);
		env_oldpwd->value = env_pwd->value;
		env_pwd->value = tmp_path;
	}
}

int built_in_cd(char** tmp, t_elist	* elist)
{
	t_env	*env_pwd;
	t_env	*env_oldpwd;
	char cwd[1024];

	env_pwd = get_env_by_key(elist, "PWD");
	env_oldpwd = get_env_by_key(elist, "OLDPWD");
	cd_arg_check(tmp, elist, env_pwd, env_oldpwd);

	
	if (chdir(tmp[1]) == -1)
		printf("IS NOT FOUND\n");
	else
	{
		env_oldpwd->value = env_pwd->value;
		getcwd(cwd, sizeof(cwd));
		env_pwd->value = cwd;
	}
	return 0;
}