/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:56:37 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 12:31:02 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Remove an entry from given dictionary (hashtable).
**
** -> dict: Pointer to dictionary where entry is to be removed.
** -> key: Character string used as unique identifier of entry to be removed.
*/

void	dict_remove(t_dict *dict, const char *key, void (*del)(void*))
{
	unsigned long int	index;
	t_node				*entry;

	if (!dict)
		return ;
	index = hash(key, dict->len);
	entry = dict->array[index];
	if (!entry)
		return ;
	while (entry->next)
	{
		if (ft_strcmp(key, entry->next->key) == 0)
		{
			entry->next = entry->next->next;
			del_entry(entry->next, del);
			dict->storage--;
			return ;
		}
		entry = entry->next;
	}
	del_entry(entry, del);
	dict->array[index] = 0;
	dict->storage--;
}
