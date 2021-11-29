/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_tild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:30:06 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 21:36:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get tild left : <
** can be input 	"<"
** can be here_doc "<<"
*/

int	get_token_tild_left(t_token *token, char *line)
{
	size_t	len;

	len = 1;
	if (line[len] == '<')
	{
		token->type = HERE_DOC;
		len = 2;
	}
	else
		token->type = INPUT_REDIRECTION;
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_timd_right()");
		return (FAILURE);
	}
	token->len = len;
	return (SUCCESS);
}

/*
** get tild right : >
** can be output 	">"
** can be append	">>"
*/

int	get_token_tild_right(t_token *token, char *line)
{
	size_t	len;

	len = 1;
	if (line[len] == '>')
	{
		token->type = APPEND;
		len = 2;
	}
	else
		token->type = OUTPUT_REDIRECTION;
	if (is_operator(line[len]))
	{
		display_syntax_error(ERR_SYMBOL, line[len], NULL);
		return (FAILURE);
	}
	token->word = ft_strdup_max(line, len);
	if (!token->word)
	{
		perror("malloc get_token_timd_right()");
		return (FAILURE);
	}
	token->len = len;
	return (SUCCESS);
}
