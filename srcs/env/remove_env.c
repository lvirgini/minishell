/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:06:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 16:56:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** remove the env with this key
**
** if first element : env = next and free first
** else swap 
*/

void	remove_t_env(t_env **env, char *key)
{
	t_env	*current;
	t_env	*next;

	if (!*env)
		return ;
	current = *env;
	if (ft_strcmp(current->key, key) == 0)
	{
		*env = current->next;
		free_this_env(current);
		return ;
	}
	while (current->next)
	{
		if (ft_strcmp(current->next->key, key) == 0)
		{
			next = current->next->next;
			free_this_env(current->next);
			current->next = next;
			return ;
		}
		current = current->next;
	}
}
