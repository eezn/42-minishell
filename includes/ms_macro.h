/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:08:24 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/06 01:05:14 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MACRO_H
# define MS_MACRO_H

# define BUFF_SIZE 1024

# define TRUE 1
# define FALSE 0

# define SQUOTE 39
# define DQUOTE 34

# define NONE 0
# define COMMAND 1
# define PATH 2
# define HEREDOC 3

# define PIPE 10
# define R_II 11
# define R_I 12
# define R_O 13
# define R_OO 14

# define WRITE 1
# define READ 0

# define PROMPT "\e[35mpico\e[0m\e[32mshell\e[0m\e[35m$ \e[0m"

/* Color */
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define PURPLE "\e[34m"
# define PINK "\e[35m"
# define BASIC "\e[37m"
# define EOC "\e[0m"

#endif
