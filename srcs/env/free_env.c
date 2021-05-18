/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:06:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:30:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free all inside a t_env
*/

static void		destroy_t_env(t_env *env)
{
	if (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
	}
}

static void		free_this_env(t_env *env)
{
	if (env)
	{
		destroy_t_env(env);
		free(env);
	}
}

/*
** free all t_env
*/

void			free_all_t_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free_this_env(env);
		env = tmp;
	}
}

/*
** remove the env with this key
*/

void			remove_t_env(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*next;

	tmp = *env;
	if (ft_strcmp(tmp->key, key) == 0)
	{
		*env = tmp->next;
		free_this_env(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (ft_strcmp(tmp->next->key, key) == 0)
		{
			next = tmp->next->next;
			free_this_env(tmp->next);
			tmp->next = next;
			return ;
		}
		tmp = tmp->next;
	}
}
