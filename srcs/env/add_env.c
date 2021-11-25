/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 16:45:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**add_new_env(char **old, char *to_add)
{
	char	**new_list_env;
	int		env_size;

	env_size = listlen(old) + 1;
	new_list_env = malloc_list(env_size);
	if (!new_list_env)
	{
		free_list(old);
		return (NULL);
	}
	list_nmove(new_list_env, old, env_size);
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

static char	*create_new_env(char *key, char *value)
{
	size_t	len;
	char	*new_env;

	if (!key || !value)
		return (NULL);
	len = ft_strlen(key) + ft_strlen(value) + 2;
	new_env = (char *)malloc(sizeof(char) * (len));
	if (!new_env)
	{
		perror("malloc create_new_env()");
		return (NULL);
	}
	ft_strlcpy(new_env, key, len);
	ft_strlcat(new_env, "=", len);
	ft_strlcat(new_env, value, len);
	return (new_env);
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
