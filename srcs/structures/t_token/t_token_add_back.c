/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:13:14 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 19:20:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_back_token(t_token **list_token, t_token *to_add)
{
	t_token *current;

	if (!list_token)
		return (FAILURE);
	current = *list_token;
	while (current)
	{
		if (!current->next)
		{
			current->next = to_add;
			to_add->prev = current;
			return (SUCCESS);
		}
		current = current->next;
	}
	*list_token = to_add;
	return (SUCCESS);
}