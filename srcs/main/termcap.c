/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:29:01 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 17:35:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Official documentation:
** https://www.gnu.org/software/termutils/manual/termcap-1.3/
*/

#include "minishell.h"

void	init_terminal_data(void)
{
	char	*termtype;
	int		success;

	termtype = ft_getenv("TERM");
	success = tgetent(NULL, termtype);
	if (success < 0)
		error_msg_and_exit("tgetent",
			"Could not access the termcap data base");
	if (success == 0)
		error_msg_and_exit("tgetent",
			"Terminal type is not defined in termcap library");
}
