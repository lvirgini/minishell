/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_something.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:28:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 13:30:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if token_type is a "word" : 
**
** included type WORD, SIMPLE QUOTE and DOUBLE QUOTE.
*/

t_bool	is_token_words(int type)
{
	static int	filename_type[3] = {WORD, SIMPLE_QUOTE, DOUBLE_QUOTE};
	size_t		i;

	i = 0;
	while (i < 3)
	{
		if (type == filename_type[i])
			return (true);
		i++;
	}
	return (false);
}

/*
** 	check if token type is a control operator ( for separate cmd)
**
**	static int	control_operator[NB_OPERATOR] = {PIPE, AND, ...}
**	in minishell only PIPE is used.
*/

t_bool	is_token_control_operator(int token_type)
{
	if (token_type == PIPE)
		return (true);
	return (false);
}
