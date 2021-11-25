/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 09:53:38 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return the env index of key or -1 if not.
*/

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		++i;
	return (i);
}

int	get_env_index(char **env, char *key)
{
	int		index;
	size_t	key_size;

	if (!env || !*env || !key)
		return (-1);
	index = 0;
	key_size = ft_strclen(key, '=');
	while (env[index])
	{
		if (ft_strncmp(env[index], key, key_size) == 0
			&& (ft_strncmp(env[index], key, key_size + 1) == -61
				|| ft_strncmp(env[index], key, key_size + 1) == '='
				|| ft_strncmp(env[index], key, key_size + 1) == 0))
			return (index);
		index++;
	}
	return (-1);
}

/*
** 	like getenv
**	return ptr corresponding to the value of key from env without key and '='.
*/

char	*get_env_value(char **env, char *key)
{
	int		index;
	char	*value;

	if (!env || !*env || !key || !*key)
		return (NULL);
	index = get_env_index(env, key);
	if (index == -1)
		return (NULL);
	value = ft_strchr(env[index], '=') + 1;
	return (value);
}
