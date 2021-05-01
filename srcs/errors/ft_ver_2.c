/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:29:45 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/28 21:23:42 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	*calloc_ver(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		error_msg_and_exit("ft_calloc", SYSERR);
	return (ptr);
}

char	*strdup_ver(const char *str)
{
	void	*ptr;

	ptr = ft_strdup(str);
	if (ptr == NULL)
		error_msg_and_exit("ft_strdup", SYSERR);
	return (ptr);
}

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
