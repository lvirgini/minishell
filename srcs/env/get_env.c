/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 21:26:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get the ptr t_env corresponding to key if existing, NULL if no exist
*/

t_env	*get_this_env(t_env **env, char *key)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*
** get value of key in t_env
** == get_env()
*/

char	*get_value_t_env(t_env **env, char *key)
{
	t_env	*required;

	required = get_this_env(env, key);
	if (required)
		return (required->value);
	return (NULL);
}
