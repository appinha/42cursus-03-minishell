/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:08:14 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/02 16:13:30 by apuchill         ###   ########.fr       */
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

void	term_clear_line(int len, int col)
{
	while (len)
	{
		term_backspace(len, col);
		len--;
	}
}
