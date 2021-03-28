/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:15 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/02 15:02:48 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
		error_msg_and_exit(SYSERR);
	ft_printf("%s%s➜ %s%s %s✗ %s ",
		C_GREEN, C_BOLD, C_PINK, cwd, C_YELLOW, C_END);
}

static void	msh_loop(void)
{
	char	*line;
	int		status;

	status = 0;
	while (status == 0)
	{
		print_prompt();
		status = get_next_line(STDIN_FILENO, &line);
		if (status < 0)
			error_msg_and_exit(SYSERR);
		ft_printf("%s", line);
		free(line);
		ft_printf("%f %i", 100.029, -123809);
	}
}

int	main(void)
{
	msh_loop();
	return (EXIT_SUCCESS);
}
