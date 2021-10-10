/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:39:55 by mini              #+#    #+#             */
/*   Updated: 2021/10/10 15:37:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	get_token_type(char	*line)
{
	static char *type[6] = { [SPECIAL_PARAMETER] = '$', [SIMPLE_QUOTE] = '\'', 
	[DOUBLE_QUOTE] = '\"', [PIPE] = '|', [INPUT_REDIRECTION] = '<', 
	[OUTPUT_REDIRECTION] = '>'};

	int	i;

	i = 0;
	while (i < 6)
	{
		if (*line == type[i])
			return (i);
	}
	return (WORD);
}
*/
/*
** get next token from line
*/

t_token	*add_next_token(char *line, t_token *token_prev, t_func *get_token)
{
	t_token			*token;
	int				syntax;

	token = malloc_token();
	if (!token)
		return (NULL);
	token->prev = token_prev;
	token->type = is_metacharacter(*line); // pas token type mais une autre variable ?
	syntax = get_token[token->type](token, line); // line + 1 ?
	if (!syntax)
		return (NULL); /// print error
	return (token);
}