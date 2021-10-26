/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 12:07:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return the env index of key or -1 if not.
*/

int	get_env_index(char **env, char *key)
{
	int		index;
	size_t	key_size;

	if (!env || !*env || !key)
		return (-1);
	index = 0;
	key_size = ft_strlen(key);
	while (env[index])
	{
		if (ft_strncmp(env[index], key, key_size) == 0
			&& env[index][key_size] == '=')
			return (index);
		index++;
	}
	return (-1);
}

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

int	get_list_env_size(char **env) //
{
	int		count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}
