/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:18:44 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** copy src in dst if src contain c char. (using malloc)
*/

int	list_ccpy(char **dst, char **src, char c)
{
	int		i;
	int		j;

	if (!dst || !src)
		return (FAILURE);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (ft_strchr(src[i], c))
		{
			dst[j] = ft_strdup(src[i]);
			if (!dst[j])
			{
				free_n_list(dst, j);
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (j);
}

/*
** count only string containing c char
*/

size_t	listclen(char **list, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (list)
	{
		while (list[i])
		{
			if (ft_strchr(list[i], c))
				len++;
			i++;
		}
	}
	return (len);
}

/*
** Duplicate only strings who contain c char
*/

char	**list_cdup(char **src, char c)
{
	size_t	len;
	char	**dst;

	if (!src)
		return (NULL);
	len = listclen(src, c);
	dst = malloc_list(len);
	if (dst)
	{
		if (list_ccpy(dst, src, c) == FAILURE)
			return (NULL);
		return (dst);
	}
	return (dst);
}

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;
//	int		env_size;

	//env_size = listlen(env);
	//minishell_env = malloc_list(env_size);
	minishell_env = list_cdup(env, '=');
	if (!minishell_env)
		return (NULL);
	export_shlvl(&minishell_env);
//	if (list_ndup(minishell_env, env, env_size) == FAILURE)//
//		return (NULL);
	return (minishell_env);
// add SHELL : shellname
}
