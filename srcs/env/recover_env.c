/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/18 10:31:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Divides the string with the first '=' to separate the key from the value
** and puts it in the new t_env.
*/

t_env		*add_t_env_with_split_key_value(char *str)
{
	int		splitter;
	char	*key;
	char	*value;
	t_env	*ret;

	splitter = ft_strchr_len(str, '=');
	key = ft_strdup_max(str, splitter);
	value = ft_strdup(str + splitter + 1);
	ret = add_new_env(key, value);
	free(key);
	free(value);
	return (ret);
}

/*
** get the complete environment send in the main argument
*/

t_env		*get_complete_env(char **env, char *shell_name)
{
	int		i;
	t_env	*ret;
	t_env	*first;

	if (!env || !*env)
		return (add_new_env("SHELL", shell_name + 2));
	ret = add_t_env_with_split_key_value(env[0]);
	if (ret == NULL)
		return (NULL);
	first = ret;
	i = 1;
	while (env[i])
	{
		ret->next = add_t_env_with_split_key_value(env[i]);
		if (ret->next == NULL)
		{
			free_all_t_env(first);
			return (NULL);
		}
		ret = ret->next;
		i++;
	}
	edit_or_add_t_env(&first, "SHELL", shell_name + 2);
	return (first);
}
