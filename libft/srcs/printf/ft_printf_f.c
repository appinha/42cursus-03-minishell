/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/02 15:48:29 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_f(int *len, t_flags fl, double n)
{
	union u_dbl	dbl;

	dbl.f = n;
	if (dbl.bits.sign > 0)
		fl.sign = '-';
	else
		fl.sign = '+';
	fl.print_n0 = 1;
	if (fl.point == 0)
		fl.precision = 6;
	if (n >= 0)
		fl.f = n;
	else
		fl.f = -n;
	fl.ulli = fl.f;
	fl.a = ft_ftoa_rnd(fl.f, fl.precision, 5);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.a, ".");
		free(fl.a);
		fl.a = fl.tmp;
	}
	print_flags(len, fl);
	free(fl.a);
}
