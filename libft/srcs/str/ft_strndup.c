/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:57:53 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/28 12:42:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: save a copy of a string (with malloc, size-bounded)
**
** DESCRIPTION:
** 		The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
** 		The strndup() function is similar, but only copies at most n bytes.  If
**	s is longer than n, only n bytes are copied, and a terminating null byte
**	('\0') is added.
*/

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;

	s2 = (char *)malloc(n + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, n);
	s2[n + 1] = 0;
	return (s2);
}
