/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:22:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 17:04:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Signal handler functions. More info: man signal.
**
** SIGINT: program interrupt signal (ctrl+C).
** SIGQUIT: (ctrl+\).
*/

void	sig_prompt(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\n");
		set_exit_status(130);
		print_prompt();
	}
}

void	signal_handler(short int caller)
{
	if (caller == PROMPT)
	{
		if (signal(SIGINT, sig_prompt) == SIG_ERR)
			error_msg_and_exit("signal_handler", SYSERR);
		if (signal(SIGQUIT, sig_prompt) == SIG_ERR)
			error_msg_and_exit("signal_handler", SYSERR);
	}
}
