/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:29:45 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/06 20:22:32 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

char	*strdup_ver(const char *s1)
{
	void	*ptr;

	ptr = ft_strdup(s1);
	if (ptr == NULL)
		error_msg_and_exit("ft_strdup", SYSERR);
	return (ptr);
}

char	**ft_split_ver(const char *s, char c)
{
	char	**ptr;

	ptr = ft_split(s, c);
	if (ptr == NULL)
		error_msg_and_exit("ft_split", SYSERR);
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

void	getcwd_ver(char *buf, size_t size)
{
	if (getcwd(buf, size) == NULL)
		error_msg_and_exit("getcwd", SYSERR);
}
