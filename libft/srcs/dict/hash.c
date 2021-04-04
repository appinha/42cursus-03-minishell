/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:12:41 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 17:51:35 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** Hash function - implementation of the djb2 hashing algorithm.
**
** -> key: Character string used as unique identifier of a dictionary entry.
** -> dict_len: Dictionary's length, i.e. its maximum number of entries.
**
** RETURN: the computed index that suggests where the entry can be found.
*/

unsigned long int	hash(const char *key, unsigned int dict_len)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (key && key[i])
		hash = ((hash << 5) + hash) + key[i++];
	return (hash % dict_len);
}
