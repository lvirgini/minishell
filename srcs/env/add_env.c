/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 17:15:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Puts the key and value in env
** 		-	key can't be empty
**		-	value can
*/

static int	puts_in_env(t_env *res, char *key, char *value)
{
	if (!key)
		return (FAILURE);
	res->key = ft_strdup(key);
	if (res->key == NULL)
	{
		perror("puts_in_env");
		return (FAILURE);
	}
	res->value = ft_strdup(value);
	if (res->value == NULL && value != NULL)
	{
		perror("puts_in_env");
		free(res->key);
		return (FAILURE);
	}
	return (SUCCESS);
}

/*
** malloc new env and puts inside key and value
*/

t_env	*add_new_env(char *key, char *value)
{
	t_env	*res;

	res = malloc_t_env();
	if (res != NULL)
	{
		if (puts_in_env(res, key, value) == FAILURE)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

/*
** add this env to front of all env
** return the fornt of env.
*/

void	add_front_env(t_env **env, t_env *to_add)
{
	if (to_add)
	{
		to_add->next = *env;
		*env = to_add;
	}
}
