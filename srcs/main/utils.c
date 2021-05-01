/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:59 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/30 22:31:52 by apuchill         ###   ########.fr       */
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

void	print_prompt(char *user)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit("getcwd", SYSERR);
	ft_printf("%s%s➜  %s %s%s %s✗ %s ",
		C_GREEN, C_BOLD, user, C_PINK, cwd, C_YELLOW, C_END);
	g_msh.len_prompt = 4 + ft_strlen(user) + 1 + ft_strlen(cwd) + 3;
}

void	set_exit_status(int status)
{
	dict_insert(g_msh.dict_env, "?", ft_itoa(status));
}

int		ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (1);
}

int		get_nbr_len(int	nbr)
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
