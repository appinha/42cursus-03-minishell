/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:41 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/22 21:12:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_a_match(char *line, int i, int *match_index, char c)
{
	while (line[i++] != '\0')
	{
		if (line[i] == c)
		{
			*match_index = i;
			return (1);
		}
	}
	return (0);
}

static int	find_end(char *line, int i, int *end)
{
	while ((line[i] != ' ') && (line[i]))
		i++;
	*end = i;
	return (i);
}

t_token *split_tokens(char *line)
{
	int		i;
	int		token_end;
	t_token	*token_lst;

	i = 0;
	token_lst = NULL;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] == '\'' || line[i] == '\"') && has_a_match(line, i, &token_end, line[i]))
			add_token(line, i + 1, token_end, &token_lst);
		else
			add_token(line, i, find_end(line, i, &token_end), &token_lst);
		i = token_end + 1;
	}
	return (token_lst);
}
