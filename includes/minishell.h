/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:23:43 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/09 12:24:45 by apuchill         ###   ########.fr       */
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
# include <term.h>
# include "libft.h"
# include "errors.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define PROMPT		0
# define EOT		4

# define DEL		127
# define ARROW_UP	"\e[A"
# define ARROW_DO	"\e[B"
# define ARROW_LE	"\e[C"
# define ARROW_RI	"\e[D"

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
typedef struct s_hist
{
	int				nbr;
	char			*cmd_line;
	struct s_hist	*prev;
	struct s_hist	*next;
}	t_hist;

typedef struct s_stream
{
	int				len_prompt;
	bool			is_history;
	char			*tmp_input;
}	t_stream;

typedef struct s_msh
{
	t_dict			*dict_env;
	struct termios	orig_term;
	t_stream		stream;
	char			*cmd_line;
	t_hist			*history;
	t_hist			*hist_curr;
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
void	print_prompt(char *user, int *len_prompt);
void	set_exit_status(int status);
void	msh_destroy(void);
/*
** FILE: signal.c
*/
void	signal_handler(short int caller);
void	sig_prompt(int signum);
/*
** FILE: termcap.c
*/
void	get_terminal_data(char *termtype);
void	init_terminal_data(char *termtype);
void	restore_terminal_data(bool from_msh_destroy);
/*
** FILE: term_handler.c
*/
int		terminal_handler(char *termtype, t_stream *stream, char *buf);
void	term_backspace(t_stream *stream, int max_len, int col);
/*
** FILE: term_utils.c
*/
int		ft_putchar_int(int c);
int		get_nbr_len(int	nbr);
void	term_clear_line(t_stream *stream, int max_len, int col);
/*
** FILE: history.c
*/
void	put_input_in_history(char *input_line);
void	erase_history(t_hist **lst);
/*
** FOLDER: builtins.c
*/
void	builtin_exit(void);
void	builtin_history(t_hist *lst);

#endif
