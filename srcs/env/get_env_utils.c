/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 13:38:17 by eassouli         ###   ########.fr       */
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

char	*dup_variable_to_plus(char *to_add, char *to_join)
{
	int		len_to_add;
	int		len_rest_add;
	int		index_value;
	char	*new_key;

	len_to_add = is_valid_key(to_add);
	if (to_add[len_to_add] == '+' && to_join)
	{
		index_value = is_valid_key(to_add) + 1;
		if (to_join[is_valid_key(to_join)] == '=')
			index_value++;
		new_key = ft_strjoin(to_join, to_add + index_value);
	}
	else
	{
		if (to_add[len_to_add] == '+')
		{
			len_rest_add = ft_strlen(to_add + len_to_add + 1);
			ft_memmove(to_add + len_to_add,
				to_add + len_to_add + 1, len_rest_add);
			to_add[len_to_add + len_rest_add] = '\0';
		}
		new_key = ft_strdup(to_add);
	}
	return (new_key);
}

int	get_env_index(char **env, char *key)
{
	int		index;
	size_t	key_size;

	if (!env || !*env || !key)
		return (-1);
	index = 0;
	key_size = is_valid_key(key);
	while (env[index])
	{
		if (ft_strncmp(env[index], key, key_size) == 0)
		{
			if (env[index][key_size] == '=' || env[index][key_size] == '\0')
				return (index);
		}
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
	value = ft_strchr(env[index], '=');
	if (value)
		return (value + 1);
	return (NULL);
}
