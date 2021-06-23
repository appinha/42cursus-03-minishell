/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/22 21:13:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *line)
{
	if (ft_strcmp(line, "exit") == 0)
		builtin_exit();
	else if (ft_strcmp(line, "") == 0)
		return ;
	else if (ft_strcmp(line, "history") == 0)
		builtin_history(g_msh.history);
	else
		ft_printf("minishell: command not found: %s\n", line);
}

//*DEBUGGING FUNC
static void	print_token_lst(t_token *token_lst)
{
	while (token_lst->next != NULL)
	{
		printf("type: %i value: %s\n", token_lst->type, token_lst->value);
		token_lst = token_lst->next;
	}
	printf("type: %i value: %s\n", token_lst->type, token_lst->value);
}

void	tokenizer(char *line)
{
	t_token	*token_lst;
	token_lst = split_tokens(line);
	print_token_lst(token_lst); //*DEBUGGING LINE
}
