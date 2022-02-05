/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_built_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:30:42 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 18:47:03 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILT_IN_H
# define MS_BUILT_IN_H

/* 리턴타입 변경 필요 */
int		check_built_in(char **token, t_elist *elist);
void	built_in_env(char **token, t_elist *elist);
void	built_in_export(char **token, t_elist *elist);
void	built_in_unset(char **token, t_elist *elist);
void	built_in_pwd(char** token);
void	built_in_cd(char** tmp, t_elist	* elist);
void	built_in_echo(char** token);
void	filter(char **token, t_elist *elist);

/* Temp */
int		heredoc(char **token);

#endif
