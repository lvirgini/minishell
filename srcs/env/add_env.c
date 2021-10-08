/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/07 19:48:05 by lvirgini         ###   ########.fr       */
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
** CARREFULL : don't use this function directly : use edit_or_add_t_env
** because we can't have two same key env
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
** return the front of env.
*/

static void	add_front_env(t_env **env, t_env *to_add)
{
	if (to_add)
	{
		to_add->next = *env;
		*env = to_add;
	}
}

/*
** Edit existing env or add it if no exist
*/

int	edit_or_add_t_env(t_env **env, char *key, char *value)
{
	t_env	*to_edit;

	to_edit = get_this_env(env, key);
	if (to_edit == NULL)
		add_front_env(env, add_new_env(key, value));
	else
	{
		free(to_edit->value);
		to_edit->value = ft_strdup(value);
		if (to_edit->value == NULL && value != NULL)
			return (FAILURE);
	}

	return (SUCCESS);
}
