/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:22:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:35:07 by apuchill         ###   ########.fr       */
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
		free(g_msh.stream.cmd_line);
		g_msh.stream.cmd_line = calloc_ver(1, sizeof(char));
		free_null((void **)&g_msh.stream.tmp_input);
		g_msh.stream.is_history = false;
		history_go_to_last(&g_msh.hist_curr);
		print_prompt(ft_getenv("USER"), &g_msh.stream.len_prompt);
	}
	if (signum == EOT)
	{
		ft_printf("exit\n");
		set_exit_status(0);
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
