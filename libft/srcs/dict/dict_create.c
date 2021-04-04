/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:06:10 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 18:29:23 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Create a new dictionary (hashtable data structure).
**
** -> len: Dictionary's length, i.e. its maximum number of entries.
**
** RETURN: a pointer to the new allocated dictionary. In case of error, a NULL
** pointer is returned.
*/

t_dict	*dict_create(unsigned int len)
{
	t_dict	*dict;

	if (len < 1)
		return (NULL);
	dict = malloc(sizeof(*dict));
	if (!dict)
		return (NULL);
	dict->array = ft_calloc(len, sizeof(t_node));
	if (!dict->array)
		return (NULL);
	dict->len = len;
	dict->storage = 0;
	return (dict);
}
