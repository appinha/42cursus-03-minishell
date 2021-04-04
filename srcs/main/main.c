/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/03 22:35:29 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(t_msh *msh)
{
	char	cwd[PATH_MAX];
	char	*user;

	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit(SYSERR);
	user = dict_get(msh->dc_environ, "USER");
	ft_printf("%s%s➜  %s %s%s %s✗ %s ",
		C_GREEN, C_BOLD, user, C_PINK, cwd, C_YELLOW, C_END);
}

static void	msh_loop(t_msh *msh)
{
	char	*line;
	int		status;

	status = 0;
	while (status == 0)
	{
		print_prompt(msh);
		status = get_next_line(STDIN_FILENO, &line);
		if (status < 0)
			error_msg_and_exit(SYSERR);
		free(line);
	}
}

static void	get_environ(t_msh *msh, char **__environ)
{
	char	**split;
	int		i;

	msh->dc_environ = dict_create(ft_strlen_2(__environ));
	i = 0;
	while (__environ[i])
	{
		split = ft_split(__environ[i], '=');
		if (split[0] && split[1])
			dict_insert(msh->dc_environ, split[0], ft_strdup(split[1]));
		else if (split[0])
			dict_insert(msh->dc_environ, split[0], ft_strdup(""));
		ft_split_free(split);
		i++;
	}
}

static void	msh_destroy(t_msh *msh)
{
	dict_destroy(msh->dc_environ);
}

int	main(void)
{
	t_msh	msh;

	get_environ(&msh, __environ);
	msh_loop(&msh);
	msh_destroy(&msh);
	return (EXIT_SUCCESS);
}
