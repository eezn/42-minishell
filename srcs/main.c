/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchpa <sangchpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:58 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/06 23:38:21 by sangchpa         ###   ########.fr       */
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
	// main_debug(envp, "echo abc 123 $USER");
	return (EXIT_SUCCESS);
}
