/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:39:55 by mini              #+#    #+#             */
/*   Updated: 2021/10/26 16:21:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** add next token from line
**		malloc empty t_token
**		check if it is metacharacter or word
**		sends to corresponding functions (t_func) get_token
**		check the syntax
*/

t_token	*add_next_token(char *line, t_func_get_token *get_token)
{
	t_token			*token;
	int				meta;
	int				syntax;

	if (!*line)
		return (NULL);
	token = malloc_token();
	if (!token)
		return (NULL);
	meta = is_metacharacter(*line);
	syntax = get_token[meta](token, line);
	if (syntax == FAILURE)
	{
		free(token);
		return (NULL);
	}	
	return (token);
}
