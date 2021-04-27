/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:29:01 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/27 09:22:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Official documentation:
** https://www.gnu.org/software/termutils/manual/termcap-1.3/
*/

#include "minishell.h"

void	get_terminal_data(char *termtype)
{
	int				ret;

	ret = tgetent(NULL, termtype);
	if (ret < 0)
		error_msg_and_exit("tgetent",
			"Could not access the termcap data base");
	if (ret == 0)
		error_msg_and_exit("tgetent",
			"Terminal type is not defined in termcap library");
}

void	init_terminal_data(char *termtype)
{
	int				ret;
	struct termios	new_term;

	get_terminal_data(termtype);
	ret = tcgetattr(STDIN_FILENO, &g_msh.orig_term);
	if (ret < 0)
		error_msg_and_exit("tcgetattr", SYSERR);
	ft_memcpy(&new_term, &g_msh.orig_term, sizeof(new_term));
	new_term.c_lflag &= ~(ECHO | ICANON);
	new_term.c_cc[VMIN] = 1;
	new_term.c_cc[VTIME] = 0;
	ret = tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_term);
	if (ret < 0)
		error_msg_and_exit("tcsetattr", SYSERR);
}

void	restore_terminal_data(bool from_exit)
{
	int				ret;

	if (from_exit == true)
	{
		ret = tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_msh.orig_term);
		if (ret == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		ret = tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_msh.orig_term);
		if (ret == -1)
			error_msg_and_exit("tcsetattr", SYSERR);
	}
}
