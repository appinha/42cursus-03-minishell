/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:15:12 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:47:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: free and null a pointer
**
** DESCRIPTION:
** 		The ft_free_null() function frees the memory space pointed to by ptr
**		and then makes the pointer null.
*/

#include "libft.h"

void	ft_free_null(void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}
