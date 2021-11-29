/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 13:36:15 by eassouli         ###   ########.fr       */
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

/*
** Malloc list + 1 to add the new element
*/

void	add_new_env(char ***env, char *to_add)
{
	char	**new_list_env;
	char	*new_key;
	int		env_size;

	env_size = listlen(*env) + 1;
	new_list_env = malloc_list(env_size);
	if (!new_list_env)
		return ;
	new_key = dup_variable_to_plus(to_add, NULL);
	if (new_key == NULL)
	{
		free(new_list_env);
		return ;
	}
	list_nmove(new_list_env, *env, env_size - 1);
	new_list_env[env_size - 1] = new_key;
	free(*env);
	*env = new_list_env;
	return ;
}

/*
** Free the element to remove and concatenate the rest of the list
*/

int	edit_env(char **env, int index, char *to_edit)
{
	char	*new_key;

	new_key = dup_variable_to_plus(to_edit, env[index]);
	if (new_key == NULL)
		return (FAILURE);
	free(env[index]);
	env[index] = new_key;
	return (SUCCESS);
}
