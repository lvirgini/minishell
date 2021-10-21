/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:42:29 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:02:10 by lvirgini         ###   ########.fr       */
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

void	free_list_token(t_token **token)
{
	t_token	*current;
	t_token	*next;

	if (!token)
		return ;
	current = *token;
	while (current)
	{
		next = current->next;
		free_this_token(current);
		current = next;
	}
	free(token);
}
