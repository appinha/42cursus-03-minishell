/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:29:45 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/25 21:37:43 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

t_dict	*dict_create_ver(unsigned int len)
{
	t_dict	*ptr;

	ptr = dict_create(len);
	if (ptr == NULL)
		error_msg_and_exit("dict_create", SYSERR);
	return (ptr);
}

void	dict_insert_ver(t_dict *dict, const char *key, void *value)
{
	if (dict_insert(dict, key, value) < 0)
		error_msg_and_exit("dict_insert", SYSERR);
}
