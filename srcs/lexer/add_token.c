/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:39:55 by mini              #+#    #+#             */
/*   Updated: 2021/10/15 13:19:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get next token from line
*/

t_token	*add_next_token(char *line, t_token *token_prev, t_func *get_token)
{
	t_token			*token;
	int				meta;
	int				syntax;

	if (!*line)
		return (NULL);
	token = malloc_token();
	if (!token)
		return (NULL);
	token->prev = token_prev;
	meta = is_metacharacter(*line);
	syntax = get_token[meta](token, line); // line + 1 ?
	if (syntax == FAILURE)
		return (NULL); /// print error
	return (token);
}
