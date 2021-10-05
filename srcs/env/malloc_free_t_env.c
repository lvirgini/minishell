/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_t_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 17:09:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Malloc t_env and set all inside to NULL.
*/

t_env	*malloc_t_env(void)
{
	t_env	*res;

	res = (t_env *)malloc(sizeof(t_env));
	if (res == NULL)
	{
		perror("malloc_env()");
		return (NULL);
	}
	res->key = NULL;
	res->value = NULL;
	res->next = NULL;
	return (res);
}

/*
** free all inside a t_env
*/

static void	destroy_this_env(t_env *env)
{
	if (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
	}
}

/*
** free only this t_env
*/

void	free_this_env(t_env *env)
{
	if (env)
	{
		destroy_this_env(env);
		free(env);
	}
}

/*
** free all t_env
*/

void	free_all_t_env(t_env **env)
{
	t_env	*next;
	t_env 	*current;

	current = *env;
	while (current)
	{
		next = current->next;
		free_this_env(current);
		current = next;
	}
	free(env);
}
