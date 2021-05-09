/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:08:14 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/09 12:12:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (1);
}

int	get_nbr_len(int	nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	term_clear_line(t_stream *stream, int max_len, int col)
{
	while (max_len)
	{
		term_backspace(stream, max_len, col);
		max_len--;
	}
}
