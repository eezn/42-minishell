/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:30:42 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 19:43:22 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/* 일단 필요한 헤더 다 사용하고 나중에 헤더 중복 정리 */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "data_structure.h"

/* Built in Functions */
void	built_in_env(t_elist *elist);
void	built_in_export(t_elist *elist, char *key, char *value);
void	built_in_unset(t_elist *elist, char *key);


int built_in_check(char *token, t_elist *elist);


int built_in_pwd(char** tmp);
// int built_in_echo(char** token);
int built_in_cd(char* token, char** tmp, t_elist	* elist);

#endif

