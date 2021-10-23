/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/23 16:36:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Malloc t_env and set all inside to NULL.
*/

char	**malloc_list_env(int env_size)
{
	char **env;

	env = (char **)malloc(sizeof(char *) * (env_size + 1));
	if (!env)
	{
		perror("malloc_env()");
		return (NULL);
	}
	env[env_size] = NULL;
	return (env);
}

char	*create_new_env(char *key, char *value)
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
