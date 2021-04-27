/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:22:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/27 09:33:26 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Signal handler functions. More info: man signal.
**
** SIGINT: program interrupt signal (ctrl + C).
** SIGQUIT: (ctrl + \).
** EOT: end of transmission (ctrl + D).
*/

void	sig_prompt(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\n");
		set_exit_status(130);
		print_prompt(ft_getenv("USER"));
	}
	if (signum == EOT)
	{
		ft_printf("exit\n");
		msh_exit();
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
