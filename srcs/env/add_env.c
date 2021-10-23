/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/23 17:30:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**add_new_env(char **old, char *to_add)
{
	char	**new_list_env;
	int		env_size;

	env_size = get_list_env_size(old) + 1;
	new_list_env = malloc_list_env(env_size);
	if (!new_list_env)
	{
		free_list_env(old);
		return (NULL);
		// si malloc fail retourner l'ancien env ou tout quitter ?
	}
	moving_env(new_list_env, old, env_size);
	new_list_env[env_size - 1] = to_add;
	new_list_env[env_size] = NULL;
	free(old);
	return (new_list_env);
}

static int	edit_env(char **env, int index, char *to_edit)
{
	free(env[index]);
	env[index] = to_edit;
	return (SUCCESS);
}

/*
** Si env "KEY" existe modifié l'index (edit env) sinon ajouter un nouvel element
*/

char	**add_env(char **env, char *key, char *value)
{
	int		index;
	char	*to_add;

	to_add = create_new_env(key, value);
	if (!to_add)
		return (env);
	index = get_env_index(env, key);
	if (index == -1)
		env = add_new_env(env, to_add);
	else
		edit_env(env, index, to_add);
	return (env);
}
