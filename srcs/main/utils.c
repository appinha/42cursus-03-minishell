/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:59 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/18 18:41:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exit_status(int status)
{
	dict_insert(g_msh.dc_environ, "?", ft_itoa(status));
}

void	print_prompt(void)
{
	char	*user;
	char	cwd[PATH_MAX];

	user = dict_get(g_msh.dc_environ, "USER");
	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit(SYSERR);
	ft_printf("%s%s➜  %s %s%s %s✗ %s ",
		C_GREEN, C_BOLD, user, C_PINK, cwd, C_YELLOW, C_END);
}
