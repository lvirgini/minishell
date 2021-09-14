/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:32:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Malloc t_env and set all inside to NULL.
*/

static t_env	*malloc_env(void)
{
	t_env	*res;

	res = (t_env *)malloc(sizeof(t_env));
	if (res == NULL)
	{
		perror(ERR_MALLOC);
		return (NULL);
	}
	res->key = NULL;
	res->value = NULL;
	res->next = NULL;
	return (res);
}

/*
** Puts the key and value in env
*/

static int		puts_in_env(t_env *res, char *key, char *value)
{
	if (!key)
		return (FAILURE);
	res->key = ft_strdup(key);
	if (res->key == NULL)
	{
		perror(ERR_MALLOC);
		return (FAILURE);
	}
	res->value = ft_strdup(value);
	if (res->value == NULL && value != NULL)
	{
		perror(ERR_MALLOC);
		free(res->key);
		return (FAILURE);
	}
	return (SUCCESS);
}

/*
** malloc new env and puts inside key and value
*/

t_env			*add_new_env(char *key, char *value)
{
	t_env	*res;

	res = malloc_env();
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
*/

int				add_front_env(t_env **env, t_env *to_add)
{
	if (env == NULL || to_add == NULL)
		return (FAILURE);
	to_add->next = *env;
	*env = to_add;
	return (SUCCESS);
}
