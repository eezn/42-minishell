/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:08:24 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/05 04:57:08 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MACRO_H
# define MS_MACRO_H

# define BUFF_SIZE 1024

# define FALSE 0
# define TRUE 1

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

# define PROMPT "\e[32mpicoshell$ \e[0m"

/* Color */
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define LAVENDER "\e[1;34m"
# define MAGENTA "\e[0;35m"
# define WHITE "\e[1;37m"
# define EOC "\e[0;0m"

#endif
