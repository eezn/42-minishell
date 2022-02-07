/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:58:14 by sangchpa          #+#    #+#             */
/*   Updated: 2022/02/07 14:47:19 by sangchpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Ctrl-C : SIGINT, Ctrl-\ : SIGQUIT
Ctrl-C : 키보드로부터 오는 인터럽트 시그널로 실행중지
Ctrl-R : eof발생.
ctrl=\ : 키보드로부터 오는 실행중지 시그널, 기본적으로 프로세스를 종료 시킨뒤 코어를 덤프하는 역활.

빈 프롬프트에서 ctrl + C를 누르면, 새로운 라인을 만들고 새로운 프롬프트를 보여줘야한다.
빈 프롬프트에서 ctrl + \를 누르면, 아무일도 생기지 않아야한다.
빈 프롬프트에서 ctrl + D를 누르면, 미니쉘이 꺼진다.

몇 가지를 작성후 ctrl + C를 누르면, 새로운 프롬프트 라인을 보여준다.
몇 가지를 작성후 ctrl + D를 누르면, 아무 일도 발생하지 않는다.
몇 가지를 작성후 ctrl + \를 누르면, 아무 일도 발생하지 않는다.

cat 이나 grep 실행중에 ctrl+c 발생시 블락.
cat 이나 grep 실행중에 ctrl+\ 발생시 블락.
cat 이나 grep 실행중에 ctrl+d 발생시 블락.
다른 커멘드와 함께 여러가지 명령 반복
만약 충돌난다면 충돌 flag 사용.
작동하지 않는 것이 있으면 불완전한 작업 플래그를 사용하십시오.
*/

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
