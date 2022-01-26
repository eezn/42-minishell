/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:39:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/26 20:13:18 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_syntax		t_syntax;
typedef struct s_tlist		t_tlist;
typedef struct s_token		t_token;

struct	s_syntax
{
	char		*original;
	t_tlist		*delimeter_tokens;
	t_tlist		*command_tokens;
	// size_t		count;
};

struct	s_tlist
{
	t_token		*head;
	t_token		*tail;
	size_t		*count;
};

struct	s_token
{
	char		*content;
	t_token		*next;
};

t_syntax	*init_syntax(char *line);
t_tlist		*create_tlist(void);
void		delete_tlist(t_tlist *tlist);
void		print_tlist(t_tlist *tlist);
void		append_token(t_tlist *tlist, char *chunk);

#endif
