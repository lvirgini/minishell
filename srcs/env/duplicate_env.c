/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:18:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/23 17:24:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** duplique l'ensemble des env
*/

int	duplicate_env(char **env, char **old, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		env[i] = ft_strdup(old[i]);
		if (!env[i])
		{
			perror("malloc in duplicate_env()");
			free_n_list_str(env, i);
			return (FAILURE);
		}
		i++;
	}
	env[i] = NULL;
	return (SUCCESS);
}

/*
** recupere les pointeurs des char *env de OLD pour les mettre dans env
*/

int	moving_env(char **env, char **old, int size)
{
	int		i;

	i = 0;
	while (i < size && old[i])
	{
		env[i] = old[i];
		i++;
	}
	return (i);
}
