/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/07 20:33:03 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unused(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
}

int	main(int argc, char **argv, char **envp)
{
	unused(argc, argv, envp);
	main_loop(envp);
	return (EXIT_SUCCESS);
}
