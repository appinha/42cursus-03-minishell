/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:19 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/08 20:15:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

static void	print_err_msg(bool is_syserr, char *function, char *msg)
{
	if (is_syserr == true)
		ft_putstr_fd(C_BOLD C_RED SYSERR C_END, STDERR_FILENO);
	else
		ft_putstr_fd(C_BOLD C_RED "Error\n" C_END, STDERR_FILENO);
	ft_putstr_fd(function, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(".\n", STDERR_FILENO);
}

void	error_msg_and_exit(char *function, char *msg)
{
	if (errno && ft_strcmp(msg, SYSERR) == 0)
		print_err_msg(true, function, strerror(errno));
	else if (ft_strcmp(msg, SYSERR) != 0)
		print_err_msg(false, function, msg);
	else
	{
		ft_putstr_fd(C_BOLD C_RED "Fatal Error" C_END " in ", STDERR_FILENO);
		ft_putstr_fd(function, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	msh_destroy();
	if (errno)
		exit(errno);
	else
		exit(EXIT_FAILURE);
}
