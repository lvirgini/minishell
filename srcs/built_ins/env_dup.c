/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:57:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 12:07:35 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}

char	**env_dup(char **env)
{
	int		i;
	int		size;
	char	**new_env;

	i = 0;
	size = 0;
	while (env && env[size])
		size++;
	new_env = malloc(sizeof(char *) * size);
	if (new_env == NULL)
		return (NULL);
	while (i < size)
	{
		new_env[i] = ft_strdup(env[i]);
		if (new_env == NULL)
		{
			free_double_str(new_env);
			free(new_env);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
