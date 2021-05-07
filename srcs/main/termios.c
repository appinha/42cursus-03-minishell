/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:08:47 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/06 20:40:47 by apuchill         ###   ########.fr       */
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

static int	term_newline(void)
{
	free_null((void **)&g_msh.tmp_input);
	ft_printf("\n");
	return (1);
}

void	term_backspace(int len, int col)
{
	if (len > 0)
	{
		g_msh.cmd_line[len - 1] = '\0';
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

static void	term_arrow(char arrow)
{
	if (!g_msh.history
		|| (arrow == 'A' && g_msh.is_history == true && !g_msh.hist_curr->prev)
		|| (arrow == 'B' && g_msh.is_history == false))
		return ;
	if (arrow == 'A' && g_msh.is_history == false)
		g_msh.tmp_input = strdup_ver(g_msh.cmd_line);
	term_clear_line(ft_strlen(g_msh.cmd_line), tgetnum("col"));
	if (arrow == 'B' && g_msh.is_history == true && !g_msh.hist_curr->next)
	{
		free_null((void **)&g_msh.cmd_line);
		g_msh.cmd_line = g_msh.tmp_input;
		g_msh.tmp_input = NULL;
		g_msh.is_history = false;
	}
	else
	{
		if (arrow == 'A' && g_msh.is_history == true)
			g_msh.hist_curr = g_msh.hist_curr->prev;
		if (arrow == 'B')
			g_msh.hist_curr = g_msh.hist_curr->next;
		free_null((void **)&g_msh.cmd_line);
		g_msh.cmd_line = strdup_ver(g_msh.hist_curr->cmd_line);
		g_msh.is_history = true;
	}
	ft_printf("%s", g_msh.cmd_line);
}

static void	term_get_char(int len, int col, char c)
{
	char	*tmp;

	if (ft_isprint(c) == false)
		return ;
	tmp = calloc_ver(1, len + 2);
	ft_memcpy(tmp, g_msh.cmd_line, len);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free_null((void **)&g_msh.cmd_line);
	g_msh.cmd_line = tmp;
	ft_printf("%c", c);
	if ((len + g_msh.len_prompt) % (col - 1) == 0)
		tputs(tgetstr("do", NULL), 1, &ft_putchar_int);
}

int	terminal_handler(char *termtype, char *buf)
{
	int	max_len;
	int	col;

	max_len = ft_strlen(g_msh.cmd_line);
	get_terminal_data(termtype);
	col = tgetnum("col");
	if (buf[0] == '\n')
		return (term_newline());
	else if (buf[0] == DEL)
		term_backspace(max_len, col);
	else if (ft_strncmp(buf, ARROW_UP, 3) == 0)
		term_arrow('A');
	else if (ft_strncmp(buf, ARROW_DO, 3) == 0)
		term_arrow('B');
	else
		term_get_char(max_len, col, buf[0]);
	return (0);
}
