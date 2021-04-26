/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:08:47 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/25 22:19:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Official documentation:
** https://pubs.opengroup.org/onlinepubs/7908799/xbd/termios.html
*/

#include "minishell.h"

static int	term_newline()
{
	ft_printf("\n");
	return (1);
}

static void	term_backspace(int len)
{
	int		col;

	col = tgetnum("col");
	if (len > 0)
	{
		g_msh.line[len - 1] = '\0';
		tputs(tgetstr("le", NULL), 1, &ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, &ft_putchar_int);
	}

	return ;
}

// static void	term_arrow()
// {
// 	return ;
// }

static void	term_get_char(int len, char c)
{
	char	*tmp;

	if (!ft_isprint(c))
		return ;
	tmp = calloc_ver(1, len + 2);
	ft_memcpy(tmp, g_msh.line, len);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(g_msh.line);
	g_msh.line = tmp;
	ft_printf("%c", c);
}

int	terminal_handler(char *buf)
{
	int	len;

	len = ft_strlen(g_msh.line);
	if (buf[0] == '\n')
		return (term_newline());
	else if (buf[0] == DEL)
		term_backspace(len);
	else
		term_get_char(len, buf[0]);
	return (0);
}
