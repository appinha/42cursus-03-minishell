/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:56:35 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/20 19:55:38 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"
# include "dict.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define SYSERR		"System error\n"

# define C_END		"\033[0m"
# define C_BOLD		"\033[1m"
# define C_RED		"\033[1;31m"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
void	msh_destroy(void);
/*
** FILE: errors.c
*/
void	error_msg_and_exit(char *function, char *msg);
/*
** FILE: ft_ver_1.c
*/
int		open_ver(const char *file);
ssize_t	read_ver(int fd, void *buf, size_t nbytes);
void	close_ver(int fd);
void	*calloc_ver(size_t count, size_t size);
/*
** FILE: ft_ver_2.c
*/
char	*strdup_ver(const char *str);
char	**ft_split_ver(const char *s, char c);
t_dict	*dict_create_ver(unsigned int len);
void	dict_insert_ver(t_dict *dict, const char *key, void *value);
void	getcwd_ver(char *buf, size_t size);

#endif
