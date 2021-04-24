/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:56:35 by apuchill          #+#    #+#             */
/*   Updated: 2021/04/24 17:16:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define SYSERR	"\033[1m\033[1;31mSystem error\033[0m\n"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: errors.c
*/
void	error_msg_and_exit(char *function, char *msg);
/*
** FILE: utils.c
*/
void	*malloc_ver(size_t size);
int		open_ver(char *file);
void	close_ver(int fd);

#endif
