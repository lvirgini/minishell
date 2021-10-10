/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:42:29 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/09 21:43:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free t_token and inside it
*/

void	free_this_token(t_token *token)
{
	if (token->word)
		free(token->word);
	free(token);
}

/*
** free all t_token **
*/

void	free_all_token(t_token **token)
{
	t_token	*current;
	t_token	*next;

	current = *token;
	while (current)
	{
		next = current->next;
		free_this_token(current);
		current = next;
	}
	free(token);
}

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

/* maybe remove multi token ?

void	remove_multi_token(t_token *first, int nb)
{
	t_token *prev;
	if (first->prev)

	while (nb --)
}*/