/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:59 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/25 22:11:06 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *env)
{
	char	*value;

	value = dict_get(g_msh.dict_env, env);
	if (!value)
		error_msg_and_exit("ft_getenv",
			"Environment variable not found.");
	return (value);
}

void	print_prompt(void)
{
	char	*user;
	char	cwd[PATH_MAX];

	user = dict_get(g_msh.dict_env, "USER");
	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit("getcwd", SYSERR);
	g_msh.len_prompt = ft_printf("%s%s➜  %s %s%s %s✗ %s ",
		C_GREEN, C_BOLD, user, C_PINK, cwd, C_YELLOW, C_END);
}

int		ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (1);
}

void	set_exit_status(int status)
{
	dict_insert(g_msh.dict_env, "?", ft_itoa(status));
}
