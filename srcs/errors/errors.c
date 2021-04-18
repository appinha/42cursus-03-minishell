/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:19 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/18 18:50:47 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

char	*get_error_code(short int category, short int elem_id, short int err_id)
{
	char	*code;

	code = malloc_ver(4 * sizeof(char));
	code[0] = category + '0';
	code[1] = elem_id + '0';
	code[2] = err_id + '0';
	code[3] = '\0';
	return (code);
}

static void	print_error_msg(char *code)
{
	int		fd;
	char	*line;
	char	*msg;

	fd = open_ver("srcs/errors/errors.txt");
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strncmp(code, line, 3) == 0)
		{
			ft_putstr_fd("\033[1m\033[1;31mError:\033[0m", STDERR_FILENO);
			msg = ft_strtrim(line, code);
			ft_putstr_fd(msg, STDERR_FILENO);
			free(msg);
			ft_putchar_fd('\n', STDERR_FILENO);
			break ;
		}
		free(line);
	}
	free(line);
	close_ver(fd);
}

void	error_msg_and_exit(char *code)
{
	if (errno && ft_strcmp(code, SYSERR) == 0)
		perror("\033[1m\033[1;31mSystem error\033[0m");
	else if (code != SYSERR)
		print_error_msg(code);
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
