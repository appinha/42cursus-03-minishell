/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:22:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/09 12:59:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Signal handler functions. More info: `man signal`.
**
** SIGINT: program interrupt signal (ctrl + C).
** SIGQUIT: (ctrl + \).
** EOT: end of transmission (ctrl + D).
*/

void	sig_prompt(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("^C\n");
		set_exit_status(130);
		free_null((void **)&g_msh.stream.tmp_input);
		free_null((void **)&g_msh.stream.cmd_line);
		print_prompt(ft_getenv("USER"), &g_msh.stream.len_prompt);
	}
	if (signum == EOT)
	{
		ft_printf("exit\n");
		builtin_exit();
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
