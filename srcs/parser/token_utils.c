/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:56:24 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/22 21:16:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_new(char *value, int type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

static t_token	*tkn_last(t_token *lst)
{
	t_token	*aux;

	if (lst == NULL)
		return (lst);
	aux = lst;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}

void	tkn_add_back(t_token **lst, t_token *new)
{
	t_token	*aux;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	aux = tkn_last(*lst);
	aux->next = new;
}
