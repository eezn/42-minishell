#include "minishell.h"

//참고링크
//https://youadokjon.tistory.com/1
void sig_handler(int signal)
{
    if (signal == SIGINT)// CTRL + C
		printf("\n\b\bminishell$\b\b");
        // printf("\n\b\bminishell$\b\b");
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