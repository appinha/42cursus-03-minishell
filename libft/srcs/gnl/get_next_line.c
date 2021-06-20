/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:42 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:54:17 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_cpy_exc_buff(char **buff, long long j)
{
	long long	i;
	char		tmp[ARG_MAX];

	i = 0;
	if (buff[0][j] == '\0')
		ft_free_null((void **)&*buff);
	else
	{
		while (buff[0][j] != '\0')
			tmp[i++] = buff[0][j++];
		tmp[i] = '\0';
		ft_free_null((void **)&*buff);
		*buff = ft_strdup(tmp);
	}
}

static int	ft_buff2line(char **line, char **buff)
{
	long long	i;
	long long	j;
	char		tmp[ARG_MAX];

	i = 0;
	j = 0;
	while (line[0][i] != '\0')
	{
		tmp[i] = line[0][i];
		i++;
	}
	ft_free_null((void **)&*line);
	while (buff[0][j] != '\0' && buff[0][j] != '\n')
		tmp[i++] = buff[0][j++];
	tmp[i] = '\0';
	*line = ft_strdup(tmp);
	if (buff[0][j] == '\n')
	{
		ft_cpy_exc_buff(&*buff, j + 1);
		return (FOUND_ENDLINE);
	}
	ft_free_null((void **)&*buff);
	return (NO_ENDLINE);
}

static char	*read_line(int fd, int *qty)
{
	char	*buff;
	char	tmp[ARG_MAX];

	*qty = read(fd, tmp, BUFFER_SIZE);
	if (*qty < 0)
		return (NULL);
	tmp[*qty] = '\0';
	buff = ft_strdup(tmp);
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	int			endline;
	int			qty;

	if (fd >= 0 && line && BUFFER_SIZE > 0)
	{
		*line = ft_strdup("");
		endline = NO_ENDLINE;
		while (endline == NO_ENDLINE)
		{
			if (buff[fd] == NULL)
				buff[fd] = read_line(fd, &qty);
			if (buff[fd] != NULL)
				qty = ft_strlen(buff[fd]);
			if (qty < 0)
				break ;
			endline = ft_buff2line(&*line, &buff[fd]);
			if (qty == 0)
				return (EOF_RCHD);
		}
		if (endline == FOUND_ENDLINE)
			return (READL_OK);
	}
	ft_free_null((void **)&*line);
	return (ERR_HPND);
}
