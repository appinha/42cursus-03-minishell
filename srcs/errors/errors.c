/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:19 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 17:23:43 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	error_msg_and_exit(char *function, char *msg)
{
	if (errno && ft_strcmp(msg, SYSERR) == 0)
	{
		ft_putstr_fd(SYSERR, STDERR_FILENO);
		perror(function);
	}
	else if (ft_strcmp(msg, SYSERR) != 0)
	{
		ft_putstr_fd("\033[1m\033[1;31mError\033[0m\n", STDERR_FILENO);
		ft_putstr_fd(function, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(".\n", STDERR_FILENO);
	}
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
