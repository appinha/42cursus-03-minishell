/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:09:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/22 21:17:05 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libft.h"
# include "dict.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define IN		0
# define OUT	1
# define READ	0
# define WRITE	1

# define T_BUILTIN	42
# define T_OPERATOR	43
# define T_LITERAL	44
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	int				builtin_cmd;
	char			*cmd;
	char			**args;
	int				pipe;
	int				redirect;
	int				fd[2];
	struct s_cmd	*next;
}	t_cmd;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/

/*
** FILE: tokenizer.c
*/
void	tokenizer(char *line);
void	parser(char *line);
/*
** FILE: split_tokens.c
*/
t_token *split_tokens(char *line);
/*
** FILE: add_token.c
*/
void	add_token(char *line, int start, int end, t_token **token_lst);
/*
** FILE: token_utils.c
*/
t_token	*tkn_new(char *value, int type);
void	tkn_add_back(t_token **lst, t_token *new);

# endif
