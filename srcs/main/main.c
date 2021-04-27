/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/27 09:32:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parser(char *line)
{
	if (ft_strcmp(line, "exit") == 0)
		msh_exit();
	if (ft_strcmp(line, "") == 0)
		return ;
	else
		ft_printf("minishell: command not found: %s\n", line);
}

static void	get_input(char *termtype)
{
	int		listen;
	char	buf[3];

	g_msh.line = calloc_ver(2, sizeof(char));
	listen = 0;
	while (listen == 0)
	{
		ft_bzero(buf, 3);
		read_ver(STDIN_FILENO, &buf, 3);
		if (buf[0] == EOT && g_msh.line[0] == '\0')
			sig_prompt(EOT);
		listen = terminal_handler(termtype, buf);
	}
}

static void	get_environ(char **__environ)
{
	char	**split;
	int		i;

	g_msh.dict_env = dict_create_ver(1024);
	i = 0;
	while (__environ[i])
	{
		split = ft_split(__environ[i], '=');
		if (!split)
			break ;
		if (split[0] && split[1])
			dict_insert_ver(g_msh.dict_env, split[0], ft_strdup(split[1]));
		else if (split[0])
			dict_insert_ver(g_msh.dict_env, split[0], ft_strdup(""));
		ft_split_free(split);
		i++;
	}
	dict_insert_ver(g_msh.dict_env, "?", ft_strdup("0"));
}

int	main(void)
{
	get_environ(__environ);
	while (true)
	{
		print_prompt(ft_getenv("USER"));
		init_terminal_data(ft_getenv("TERM"));
		signal_handler(PROMPT);
		get_input(ft_getenv("TERM"));
		restore_terminal_data(false);
		parser(g_msh.line);
		free(g_msh.line);
	}
	return (EXIT_SUCCESS);
}
