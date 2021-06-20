/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:54:31 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:34:08 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_go_to_last(t_hist **lst)
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
	history_go_to_last(&last);
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

	history_go_to_last(&g_msh.hist_curr);
	if (is_valid_cmd(input_line) == false)
		return ;
	new = calloc_ver(1, sizeof(t_hist));
	new->cmd_line = strdup_ver(input_line);
	history_lstadd_back(g_msh.hist_curr, new);
}

void	erase_history(t_hist **lst)
{
	t_hist	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		free((*lst)->cmd_line);
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}
