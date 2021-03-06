/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:59 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 13:18:26 by apuchill         ###   ########.fr       */
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

void	print_prompt(char *user, int *len_prompt)
{
	char	cwd[PATH_MAX];

	getcwd_ver(cwd, PATH_MAX);
	ft_printf(C_BOLD C_GREEN "➜  %s " C_PINK "%s " C_YELLOW "✗ " C_END,
		user, cwd);
	*len_prompt = 3 + ft_strlen(user) + 1 + ft_strlen(cwd) + 3;
}

void	set_exit_status(int status)
{
	dict_insert(g_msh.dict_env, "?", ft_itoa(status));
}

void	msh_destroy(void)
{
	dict_destroy(g_msh.dict_env, free);
	ft_free_null((void **)&g_msh.stream.cmd_line);
	ft_free_null((void **)&g_msh.stream.tmp_input);
	erase_history(&g_msh.history);
	g_msh.hist_curr = NULL;
	restore_terminal_data(true);
}
