/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:39:53 by jin-lee           #+#    #+#             */
/*   Updated: 2022/02/04 19:17:20 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

typedef struct s_tlist		t_tlist;
typedef struct s_elist		t_elist;
typedef struct s_token		t_token;
typedef struct s_env		t_env;
typedef struct s_node		t_node;

struct	s_tlist
{
	t_token		*head;
	t_token		*tail;
	size_t		count;
};

struct s_elist
{
	t_env		*head;
	t_env		*tail;
	size_t		count;
};

struct	s_token
{
	int			type;
	char		*content;
	t_token		*next;
};

struct	s_env
{
	char		*key;
	char		*value;
	t_env		*next;
};

struct s_node
{
	int			root;
	int			type;
	char		*content;
	t_node		*lnode;
	t_node		*rnode;
};

/* Token List */
t_tlist		*create_token_list(void);
void		delete_token_list(t_tlist *tlist);
void		append_token(t_tlist *tlist, char *chunk);

/* Token List Utils */
void		print_token_list(t_tlist *tlist);
void		analize_token_list(t_tlist *tlist);

/* Environment Valuable List */
t_elist		*create_env_list(void);
void		delete_env_list(t_elist *elist);
void		append_env(t_elist *elist, char *key, char *value);

/* Environment Valuable List Utils */
void		print_env(t_env	*env);
void		print_env_list(t_elist *elist);
t_env		*get_env_by_key(t_elist *elist, char *key);

/* Abstract Syntax Tree */
t_node		*get_astree(t_tlist *tlist);
t_node		*insert_astree(t_node *astree, t_node *insert);
void		delete_astree(t_node *astree);

#endif
