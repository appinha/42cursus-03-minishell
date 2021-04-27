/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:08:47 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/27 09:24:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Official documentation:
** https://www.gnu.org/software/termutils/manual/termcap-1.3/
** https://pubs.opengroup.org/onlinepubs/7908799/xbd/termios.html
**
** Code names of terminal capabilities:
**  • "up" - move the cursor vertically up one line.
**  • "do" - move the cursor vertically down one line.
**  • "ch" - position the cursor at column c in the same line.
**  • "dc" - delete one character position at the cursor.
**  • "le" - move the cursor left one column.
*/

#include "minishell.h"

static int	term_newline()
{
	ft_printf("\n");
	return (1);
}

static void	term_backspace(int len, int col)
{
	if (len > 0)
	{
		g_msh.line[len - 1] = '\0';
		tputs(tgetstr("le", NULL), 1, &ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, &ft_putchar_int);
		if ((g_msh.len_prompt + len) % (col) == 0)
		{
			tputs(tgetstr("up", NULL), 1, &ft_putchar_int);
			tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, &ft_putchar_int);
			tputs(tgetstr("dc", NULL), 1, &ft_putchar_int);
		}
	}
	return ;
}

// static void	term_arrow()
// {
// 	return ;
// }

static void	term_get_char(int len, int col, char c)
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
	if ((len + g_msh.len_prompt) % (col - 1) == 0)
		tputs(tgetstr("do", NULL), 1, &ft_putchar_int);

}

int	terminal_handler(char *termtype, char *buf)
{
	int	len;
	int	col;

	len = ft_strlen(g_msh.line);
	get_terminal_data(termtype);
	col = tgetnum("col");
	if (buf[0] == '\n')
		return (term_newline());
	else if (buf[0] == DEL)
		term_backspace(len, col);
	else
		term_get_char(len, col, buf[0]);
	return (0);
}
