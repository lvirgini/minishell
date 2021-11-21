/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:17:03 by mini              #+#    #+#             */
/*   Updated: 2021/11/21 20:31:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strlen_quote(char *line, int len, char quote_type)
{
	int	quotes_len;

	quotes_len = ft_strchr_len(line + len + 1, quote_type);
	if (quotes_len == -1)
	{
		print_syntax_error(ERR_QUOTES_NOT_CLOSED, 0, line);
		return (-1);
	}
	return (len + quotes_len + 2);
}

t_bool	is_quotes(char c)
{
	if (c == CHAR_SIMPLE_QUOTE || c == CHAR_DOUBLE_QUOTE)
		return (true);
	return (false);
}

int	get_token_word_len(char *line)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (is_quotes(line[len]))
		{
			len = strlen_quote(line, len, line[len]);
			if (len == -1)
				return (-1);
		}
		else if (!is_metacharacter(line[len]) && !ft_isspace(line[len]))
			len++;
		else
			return (len);
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
