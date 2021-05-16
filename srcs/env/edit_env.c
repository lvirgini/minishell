/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 18:17:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** get the ptr t_env corresponding to key if existing, NULL if no exist
*/

t_env		*get_this_env(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

/*
** Edit existing env or add it if no exist
*/

int			edit_or_add_t_env(t_env **env, char *key, char *value)
{
	t_env	*ptr;

	if (!env)
		return (FAILURE);
	ptr = get_this_env(*env, key);
	if (ptr == NULL)
		add_front_env(env, add_new_env(key, value));
	else
	{
		free(ptr->value);
		ptr->value = ft_strdup(value);
		if (ptr->value == NULL)
		{
			perror(ERR_MALLOC);
			return (FAILURE);
		}	
	}
	return (SUCCESS);
}

/*
** = getenv
*/

char		*get_value_t_env(t_env *env, char *key)
{
	t_env	*ptr;

	ptr = get_this_env(env, key);
	if (ptr)
		return (ptr->value);
	return (NULL);
}