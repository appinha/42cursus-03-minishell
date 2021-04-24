/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:23:43 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 16:31:53 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <termcap.h>
# include "libft.h"
# include "errors.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define PROMPT		0

# define C_END		"\033[0m"
# define C_BOLD		"\033[1m"
# define C_PINK		"\033[38;5;13m"
# define C_BLUE		"\033[38;5;75m"
# define C_MAGENTA	"\033[38;5;199m"
# define C_GREEN	"\033[1;32m"
# define C_RED		"\033[1;31m"
# define C_YELLOW	"\033[1;33m"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_msh
{
	t_dict	*dict_env;
}	t_msh;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              GLOBAL VARIABLES
*/
t_msh	g_msh;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: utils.c
*/
char	*ft_getenv(char *env);
void	print_prompt(void);
void	set_exit_status(int status);
/*
** FILE: signal.c
*/
void	signal_handler(short int caller);
void	sig_prompt(int signum);
/*
** FILE: termcap.c
*/
void	init_terminal_data(void);
/*
** FOLDER: builtins.c
*/
void	msh_destroy(void);
void	msh_exit(void);

#endif
