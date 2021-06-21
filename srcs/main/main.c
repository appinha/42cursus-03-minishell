/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/21 13:12:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_line(char *termtype, t_stream *stream)
{
	int		listen;
	char	buf[3];
	char	*tmp;

	stream->is_history = false;
	stream->cmd_line = calloc_ver(1, sizeof(char));
	listen = 0;
	while (listen == 0)
	{
		ft_bzero(buf, 3);
		read_ver(STDIN_FILENO, &buf, 3);
		if (buf[0] == EOT && stream->cmd_line[0] == '\0')
			sig_prompt(EOT);
		listen = terminal_handler(termtype, stream, buf);
	}
	ft_free_null((void **)&stream->tmp_input);
	tmp = ft_strtrim(stream->cmd_line, " "); //TODO: include return check NULL
	ft_free_null((void **)&stream->cmd_line);
	stream->cmd_line = tmp;
}

static void	get_environ(char **__environ)
{
	char	**split;
	int		i;

	g_msh.dict_env = dict_create_ver(1024);
	i = 0;
	while (__environ[i])
	{
		split = ft_split_ver(__environ[i], '=');
		if (split[0] && split[1])
			dict_insert_ver(g_msh.dict_env, split[0], ft_strdup(split[1]));
		else if (split[0])
			dict_insert_ver(g_msh.dict_env, split[0], ft_strdup(""));
		ft_split_free(split);
		i++;
	}
	dict_insert_ver(g_msh.dict_env, "?", ft_strdup("0"));
}

int	main(int argc, char *argv[])
{
	if (argc > 1 && argv)
		error_msg_and_exit("minishell", "too many arguments");
	ft_bzero(&g_msh, sizeof(t_msh));
	get_environ(__environ);
	while (true)
	{
		print_prompt(ft_getenv("USER"), &g_msh.stream.len_prompt);
		init_terminal_data(ft_getenv("TERM"));
		signal_handler(PROMPT);
		read_line(ft_getenv("TERM"), &g_msh.stream);
		restore_terminal_data(false);
		parser(g_msh.stream.cmd_line);
		put_input_in_history(g_msh.stream.cmd_line);
		ft_free_null((void **)&g_msh.stream.cmd_line);
	}
	return (EXIT_SUCCESS);
}
