/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:56:44 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/09 23:29:31 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_home(t_env *pwd, t_env *oldpwd, t_env	*home)
{
	free(oldpwd->value);
	oldpwd->value = ft_strdup(pwd->value);
	chdir(home->value);
	free(pwd->value);
	pwd->value = ft_strdup(home->value);
}

static void	cd_oldpwd(t_env *pwd, t_env *oldpwd)
{
	char	*tmp_path;

	tmp_path = ft_strdup(oldpwd->value);
	chdir(oldpwd->value);
	free(oldpwd->value);
	oldpwd->value = ft_strdup(pwd->value);
	free(pwd->value);
	pwd->value = ft_strdup(tmp_path);
	free(tmp_path);
}

static int	cd_arg_check(char **tmp, t_elist *elist, t_env *pwd, t_env *oldpwd)
{
	t_env	*home;

	home = get_env_by_key(elist, "HOME");
	if (tmp[1] != 0 && tmp[2] != 0)
	{
		elist->exit_status = -1;
		return (printf("cd: too many arguments\n"));
	}
	else if (tmp[1] == 0 || (tmp[1][0] == '~' && ft_strlen(tmp[1]) == 1))
		cd_home(pwd, oldpwd, home);
	else if (tmp[1][0] == '-' && ft_strlen(tmp[1]) == 1)
	{
		printf("%s\n", oldpwd->value);
		cd_oldpwd(pwd, oldpwd);
	}
	else
		return (0);
	return (1);
}

void	built_in_cd(char **tmp, t_elist	*elist)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	cwd[1024];

	pwd = get_env_by_key(elist, "PWD");
	oldpwd = get_env_by_key(elist, "OLDPWD");
	if (cd_arg_check(tmp, elist, pwd, oldpwd) > 0)
		return ;
	if (chdir(tmp[1]) == -1)
	{
		print_error(tmp[1], ": No such file or directory");
		elist->exit_status = -1;
	}	
	else
	{
		free(oldpwd->value);
		oldpwd->value = ft_strdup(pwd->value);
		getcwd(cwd, sizeof(cwd));
		free(pwd->value);
		pwd->value = ft_strdup(cwd);
	}
}
