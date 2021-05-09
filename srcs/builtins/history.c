/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:14:25 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/08 21:52:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
