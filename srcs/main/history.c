/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:54:31 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/02 19:47:49 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	history_lstlast(t_hist **lst)
{
	if (!*lst)
		return ;
	while ((*lst)->next)
		(*lst) = (*lst)->next;
}

static void	history_lstadd_back(t_hist *last, t_hist *new)
{
	if (!new)
		return ;
	if (!last)
	{
		new->nbr = 1;
		g_msh.history = new;
		g_msh.hist_curr = new;
		return ;
	}
	history_lstlast(&last);
	new->nbr = last->nbr + 1;
	last->next = new;
	new->prev = last;
	g_msh.hist_curr = new;
}

static bool	is_valid_cmd(char *input_line)
{
	if (input_line[0] == '\0')
		return (false);
	if (!g_msh.history)
		return (true);
	if (ft_strcmp(input_line, g_msh.hist_curr->cmd_line) == 0)
		return (false);
	return (true);
}

void	put_input_in_history(char *input_line)
{
	t_hist	*new;

	history_lstlast(&g_msh.hist_curr);
	if (is_valid_cmd(input_line) == false)
		return ;
	new = calloc_ver(1, sizeof(t_hist));
	new->cmd_line = strdup_ver(input_line);
	history_lstadd_back(g_msh.hist_curr, new);
}

void	print_history(t_hist *node)
{
	int	max_len;
	int	padding;

	if (!g_msh.history)
		return ;
	max_len = get_nbr_len(g_msh.hist_curr->nbr) + 1;
	while (node->next || g_msh.history->nbr == 1)
	{
		padding = max_len - get_nbr_len(node->nbr);
		while (padding--)
			ft_putchar(' ');
		ft_printf("%i  %s\n", node->nbr, node->cmd_line);
		if (!node->next)
			return ;
		node = node->next;
	}
}
