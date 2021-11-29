/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:17:03 by mini              #+#    #+#             */
/*   Updated: 2021/11/27 21:37:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strlen_simple_quote(char *line, int len)
{
	int	quotes_len;

	quotes_len = ft_strchr_len(line + len + 1, CHAR_SIMPLE_QUOTE);
	if (quotes_len == -1)
	{
		display_syntax_error(ERR_QUOTES_NOT_CLOSED, 0, line);
		return (-1);
	}
	return (len + quotes_len + 2);
}

int	strlen_double_quote(char *line, int len)
{
	int	quotes_len;

	quotes_len = 1;
	while (line[len + quotes_len])
	{
		if (line[len + quotes_len] == BACKSLASH)
			quotes_len++;
		else if (line[len + quotes_len] == CHAR_DOUBLE_QUOTE)
			return (len + quotes_len + 1);
		quotes_len++;
	}
	display_syntax_error(ERR_QUOTES_NOT_CLOSED, 0, line);
	return (-1);
}

int	get_token_word_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && !is_metacharacter(line[len]) && !ft_isspace(line[len]))
	{
		if (line[len] == CHAR_SIMPLE_QUOTE)
		{
			len = strlen_simple_quote(line, len);
			if (len == -1)
				return (-1);
		}
		else if (line[len] == CHAR_DOUBLE_QUOTE)
		{
			len = strlen_double_quote(line, len);
			if (len == -1)
				return (-1);
		}
		else
			len++;
	}
	return (len);
}

/*
** get token WORD : 
**		while is not a space or metacharacter or space.
*/

int	get_token_word(t_token *token, char *line)
{
	int	len;

	len = get_token_word_len(line);
	if (len == -1)
		return (FAILURE);
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_word()");
		return (FAILURE);
	}
	token->type = WORD;
	token->len = len;
	return (SUCCESS);
}
