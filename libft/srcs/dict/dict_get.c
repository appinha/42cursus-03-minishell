/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:42:46 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 18:52:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Get value of given key in given dictionary (hashtable).
**
** -> dict: Pointer to dictionary where entry is to be found.
** -> key: Character string used as unique identifier to find entry.
**
** RETURN: Entry value (pointer to any type) or NULL if key was not found.
*/

void	*dict_get(t_dict *dict, const char *key)
{
	unsigned long int	index;
	t_node				*entry;

	if (!dict)
		return (NULL);
	index = hash(key, dict->len);
	entry = dict->array[index];
	while (entry)
	{
		if (ft_strcmp(key, entry->key) == 0)
			break ;
		entry = entry->next;
	}
	if (!entry)
		return (NULL);
	return (entry->value);
}
