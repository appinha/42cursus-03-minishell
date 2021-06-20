/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:42:45 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 13:20:19 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libft.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_node {
	char			*key;
	void			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_dict {
	t_node			**array;
	unsigned int	len;
	unsigned int	storage;
}	t_dict;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
t_dict			*dict_create(unsigned int len);
void			dict_destroy(t_dict *dict, void (*del)(void*));
int				dict_insert(t_dict *dict, const char *key, void *value);
void			dict_remove(t_dict *dict, const char *key, void (*del)(void*));
void			*dict_get(t_dict *dict, const char *key);
/*
** Auxiliary functions
*/
void			del_entry(t_node *entry, void (*del)(void*));
unsigned long	hash(const char *key, unsigned int dict_len);

#endif
