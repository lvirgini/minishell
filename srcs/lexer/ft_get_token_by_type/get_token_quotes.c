/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:28:52 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 17:01:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get_token_simple_quote
**
** simple quote don't convert escape character or variable $VARIABLE.
*/

int	get_token_simple_quote(t_token *token, char *line)
{
	size_t	len;

	len = 1;
	while (line[len] && line[len] != '\'')
		len++;
	if (line[len] == '\0')
	{
		print_syntax_error(ERR_QUOTES_NOT_CLOSED, 0, line);
		return (FAILURE);
	}
	len++;
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_simple_quote()");
		return (FAILURE);
	}
	token->type = SIMPLE_QUOTE;
	token->len = len;
	return (SUCCESS);
}

/*
** get token double quote
**
** double quote convert escape character and $VARIABLE on their good values
*/

int	get_token_double_quote(t_token *token, char *line)
{
	size_t	len;

	len = 1;
	while (line[len] && line[len] != '\"')
		len++;
	if (line[len] == '\0')
	{
		print_syntax_error(ERR_QUOTES_NOT_CLOSED, 0, line);
		return (FAILURE);
	}
	len++;
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_simple_quote()");
		return (FAILURE);
	}
	token->type = DOUBLE_QUOTE;
	token->len = len;
	return (SUCCESS);
}
