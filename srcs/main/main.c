/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/25 23:16:55 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit(SYSERR);
	ft_printf("%s%s➜ %s%s %s✗ %s ", C_GREEN, C_BOLD, C_PINK, cwd, C_YELLOW, C_END);
}

static void	msh_loop(void)
{
	char	*line;
	char	**args;
	bool	status;

	status = true;
	while (status == true)
	{
		print_prompt();
		// line = read_line();
		// args = split_line(line);
		// free(line);
		// status = execute(args);
		// free(args);
		status = 0;
	}
}

int		main(void)
{
	// ignore_signal_for_shell();
	msh_loop();
	return (EXIT_SUCCESS);
}
