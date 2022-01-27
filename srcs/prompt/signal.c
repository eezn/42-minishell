/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:58:14 by sangchpa          #+#    #+#             */
/*   Updated: 2022/01/27 15:58:15 by sangchpa         ###   ########.fr       */
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
* 몇 가지를 작성후 ctrl + \를 누르면, 미니쉘이 꺼진다.
cat 이나 grep 실행중에 ctrl+c 발생시 블락.
cat 이나 grep 실행중에 ctrl+\ 발생시 블락.
cat 이나 grep 실행중에 ctrl+d 발생시 블락.
다른 커멘드와 함께 여러가지 명령 반복
만약 충돌난다면 충돌 flag 사용.
작동하지 않는 것이 있으면 불완전한 작업 플래그를 사용하십시오.
*/

//참고링크
// https://youadokjon.tistory.com/1
void sig_handler(int signal)
{
    if (signal == SIGINT)// CTRL + C
	{
		rl_replace_line("", 1);
		printf("\b\b");
		printf("\n\b\bpicoshell$ ");
        // printf("\n\b\bminishell$\b\b");
	}
    else if (signal == SIGTERM)// CTRL + D
        exit(-1);    
    else
	{
		printf("\n\b\b");
		printf("ctrl + /");// CTRL + /
	}
}

void setting_signal()
{
    signal(SIGINT, sig_handler);  // CTRL + C
    signal(SIGTERM, sig_handler); // CTRL + D
    signal(SIGQUIT, sig_handler); // CTRL + /
}

//입력시 종료안되는 문제