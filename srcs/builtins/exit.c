/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:59:31 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/18 18:39:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_destroy(void)
{
	dict_destroy(g_msh.dc_environ);
}

void	msh_exit(void)
{
	msh_destroy();
	exit(0);
}
