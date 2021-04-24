/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 17:16:03 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_loop(void)
{
	char	*line;
	int		status;

	while (true)
	{
		signal_handler(PROMPT);
		print_prompt();
		status = get_next_line(STDIN_FILENO, &line);
		if (status < 0)
			error_msg_and_exit("get_next_line", SYSERR);
		if (ft_strcmp(line, "exit") == 0)
			msh_exit();
		else
			ft_printf("minishell: command not found...\n");
		free(line);
	}
}

static void	get_environ(char **__environ)
{
	char	**split;
	int		i;

	g_msh.dict_env = dict_create(1024);
	i = 0;
	while (__environ[i])
	{
		split = ft_split(__environ[i], '=');
		if (split[0] && split[1])
			dict_insert(g_msh.dict_env, split[0], ft_strdup(split[1]));
		else if (split[0])
			dict_insert(g_msh.dict_env, split[0], ft_strdup(""));
		ft_split_free(split);
		i++;
	}
	dict_insert(g_msh.dict_env, "?", ft_strdup("0"));
}

int	main(void)
{
	get_environ(__environ);
	init_terminal_data();
	msh_loop();
	return (EXIT_SUCCESS);
}
