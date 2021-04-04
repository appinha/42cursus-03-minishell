/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:08:06 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 21:40:55 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Destroy (free) given dictionary (hashtable data structure).
**
** -> dict: Pointer to dictionary to be destroyed.
*/

void	free_entry(t_node *entry)
{
	free(entry->key);
	free(entry->value);
	free(entry);
}

void	dict_destroy(t_dict *dict)
{
	unsigned long int	index;
	t_node				*aux;

	if (!dict)
		return ;
	index = 0;
	while (index < dict->len)
	{
		if (dict->array[index])
		{
			while (dict->array[index])
			{
				aux = dict->array[index]->next;
				free_entry(dict->array[index]);
				dict->array[index] = aux;
			}
			dict->array[index] = 0;
		}
		index++;
	}
	free(dict->array);
	free(dict);
}
