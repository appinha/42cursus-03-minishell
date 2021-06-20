/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:39:43 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 12:28:55 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	del_entry(t_node *entry, void (*del)(void*))
{
	free(entry->key);
	del(entry->value);
	free(entry);
}
