/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:39:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/01/27 04:27:35 by jin-lee          ###   ########.fr       */
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
typedef struct s_elist		t_elist;

typedef struct s_token		t_token;
typedef struct s_env		t_env;

struct	s_tlist
{
	t_token		*head;
	t_token		*tail;
	size_t		*count;
};

struct s_elist
{
	t_env		*head;
	t_env		*tail;
	size_t		*count;
};

struct	s_token
{
	char		*content;
	t_token		*next;
};

struct	s_env
{
	char		*key;
	char		*value;
	t_env		*next;
};

/* Token List */
t_tlist		*create_token_list(void);
void		delete_token_list(t_tlist *tlist);
void		append_token(t_tlist *tlist, char *chunk);

/* Token List Utils */
void		print_token_list(t_tlist *tlist);

/* Environment Valuable List */
t_elist		*create_env_list(void);
void		delete_env_list(t_elist *elist);
void		append_env(t_elist *elist, char *key, char *value);

/* Environment Valuable List Utils */
void		print_env(t_env	*env);
void		print_env_list(t_elist *elist);
t_env		*get_env_by_key(t_elist *elist, char *key);

#endif
