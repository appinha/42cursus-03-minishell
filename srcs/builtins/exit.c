/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:59:31 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/25 21:21:52 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_destroy(void)
{
	dict_destroy(g_msh.dict_env);
	if (g_msh.line)
		free(g_msh.line);
}

void	msh_exit(void)
{
	msh_destroy();
	restore_terminal_data(true);
	exit(EXIT_SUCCESS);
}
