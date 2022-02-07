/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:58:14 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/07 20:26:13 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_parent(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("%c[K\n", 27);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_execve(int signal)
{
	if (signal == SIGINT)
		printf("\n");
	if (signal == SIGQUIT)
		printf("Quit: 3\n");
}

void	setting_execve_signal(void)
{
	signal(SIGINT, sig_execve);
	signal(SIGQUIT, sig_execve);
}

void	setting_parent_signal(void)
{
	signal(SIGINT, sig_parent);
	signal(SIGQUIT, SIG_IGN);
}
