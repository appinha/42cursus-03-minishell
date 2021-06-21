/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/21 14:08:19 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_command(char *line)
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

static int	is_within_quotes(const char *str, int i)
{
	if (str[i - 1] == '\'' && str[i + 1] == '\'')
		return (1);
	if (str[i - 1] == '"' && str[i + 1] == '"')
		return (1);
	return (0);
}

static char	*ft_strchr_without_quotes(const char *str, int c, int *length)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((c == str[i]) && !(is_within_quotes(str, i)))
		{
			*length = i;
			return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

void	parser(char *line)
{
	char	*semicolon;
	char	*command_str;
	int		length;

	length = 0;
	semicolon = ft_strchr_without_quotes(line, ';', &length);
	if (!(semicolon))
	{
		parse_command(line);
		return ;
	}
	command_str = ft_substr(line, 0, length);
	if (!(command_str))
		return ;//TODO linkar com saída de erro do minishell
	parse_command(command_str);
	line += ft_strlen(command_str) + 1;
	free(command_str);
	return (parser(line));
}
