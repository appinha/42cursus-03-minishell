/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:06 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:48:18 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	open_ver(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg_and_exit("open", SYSERR);
	return (fd);
}

ssize_t	read_ver(int fd, void *buf, size_t nbytes)
{
	ssize_t	ret;

	ret = read(fd, buf, nbytes);
	if (ret < 0)
		error_msg_and_exit("read", SYSERR);
	return (ret);
}

void	close_ver(int fd)
{
	if (close(fd) < 0)
		error_msg_and_exit("close", SYSERR);
}

void	*calloc_ver(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		error_msg_and_exit("ft_calloc", SYSERR);
	return (ptr);
}
