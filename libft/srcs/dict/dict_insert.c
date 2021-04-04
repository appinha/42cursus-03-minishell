/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:53:47 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 21:37:17 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Insert a new entry (key-value pair) to a given dictionary (hashtable).
**
** -> dict: Pointer to dictionary where entry is to be inserted.
** -> key: Character string used as unique identifier of the new entry.
** -> value: Pointer to any type of stored value.
**
** RETURN: 0 in case of successful insertion, -1 otherwise.
*/

static void	insert_entry(t_dict *dict, t_node *new_entry)
{
	unsigned long int	index;
	t_node				*tmp;

	index = hash(new_entry->key, dict->len);
	if (!dict->array[index])
		dict->array[index] = new_entry;
	else
	{
		tmp = dict->array[index];
		while (tmp->next)
		{
			if (ft_strcmp(tmp->key, new_entry->key) == 0)
			{
				free(tmp->value);
				tmp->value = new_entry->value;
				free(new_entry->key);
				free(new_entry);
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = new_entry;
	}
}

int	dict_insert(t_dict *dict, const char *key, void *value)
{
	t_node	*new_entry;

	if (!dict)
		return (-1);
	new_entry = ft_calloc(1, sizeof(t_node));
	if (!new_entry)
		return (-1);
	new_entry->key = ft_strdup(key);
	new_entry->value = value;
	new_entry->next = NULL;
	insert_entry(dict, new_entry);
	dict->storage++;
	return (0);
}
