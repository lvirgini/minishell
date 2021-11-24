/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:55:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:15:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_env(char ***env, char *to_add)
{
	char	**new_list_env;
	char	*new_key;
	int		env_size;

	env_size = listlen(*env) + 1;
	new_list_env = malloc_list(env_size);
	if (!new_list_env)
		return ;
	new_key = ft_strdup(to_add);
	if (new_key == NULL)
	{
		free(new_list_env);
		return ;
	}
	list_nmove(new_list_env, *env, env_size - 1); //
	new_list_env[env_size - 1] = new_key;
	free(*env);
	*env = new_list_env;
	return ;
}

int	edit_env(char **env, int index, char *to_edit)
{
	char	*new_key;

	new_key = ft_strdup(to_edit);
	if (new_key == NULL)
		return (FAILURE); // Secure malloc
	free(env[index]);
	env[index] = new_key;
	return (SUCCESS);
}

/*
** Si env "KEY" existe modifié l'index (edit env) sinon ajouter un nouvel element
*/

// char	**add_env(char **env, char *key, char *value)
// {
// 	int		index;
// 	char	*to_add;

// 	to_add = create_new_env(key, value);
// 	if (!to_add)
// 		return (env);
// 	index = get_env_index(env, key);
// 	if (index == -1)
// 		env = add_new_env(env, to_add);
// 	else
// 		edit_env(env, index, to_add);
// 	return (env);
// }
