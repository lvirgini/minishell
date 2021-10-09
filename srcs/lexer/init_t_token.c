/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mini <mini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:50:07 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/09 18:47:41 by mini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** malloc empty t_token
*/

t_token	*malloc_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		perror("malloc_token ()");
		return (NULL);
	}
	ft_memset(token, 0, sizeof(t_token));
	return (token);
}

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