/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:47:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 14:56:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** remove only one token and re-construct the good list of token
*/

void	remove_this_token(t_token *token)
{
	if (token->prev && token->next)
	{
		token->prev->next = token->next;
		token->next->prev = token->prev;
	}	
	free_this_token(token);
}

/*
** remove multi token : 
** remove nb token as token as first to remove
** token->prev ->next = last_next token
** last_next token->prev = prev
**	
**	example for nb = 2
**
**	PREV		TOKEN(freed)	TOKEN(freed)	NEXT
**				free			free			prev-> PREV
**	next->NEXT	free			free
*/

t_token	*remove_multi_token(t_token **list_token, t_token *token, int nb)
{
	t_token		*prev;
	t_token		*next;

	if (!token)
		return (NULL);
	prev = token->prev;
	while (nb > 0 && token)
	{
		next = token->next;
		free_this_token(token);
		token = NULL;
		token = next;
		nb--;
	}
	if (prev)
		prev->next = token;
	else
		*list_token = token;
	if (!token)
		return (NULL);
	token->prev = prev;
	return (token);
}
