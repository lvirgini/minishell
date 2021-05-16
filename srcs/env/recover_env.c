/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 18:15:00 by lvirgini         ###   ########.fr       */
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
** if not exist, add this env.
*/

static int	check_exist_or_add_env(t_env **env, char *key, char *value)
{
	t_env	*ptr;
	
	ptr = get_this_env(*env, key);
	if (ptr == NULL)
		if (add_front_env(env, add_new_env(key, value)) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

/*
** check or add the minimum needed ENV for minishell working
*/

int			check_and_set_minimum_t_env(t_env **env, char *shell_name)
{

	edit_or_add_t_env(env, "SHELL", shell_name + 2);
	if (check_exist_or_add_env(env, "USER", "user") == FAILURE)
		return (FAILURE);
	if (check_exist_or_add_env(env, "PWD", "/home") == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
** get the complete environment send in the main argument
*/

t_env		*get_complete_env(char **env, char *shell_name)
{
	int		i;
	t_env	*ret;
	t_env	*first;

	if (!env)
		return (add_new_env("SHELL", shell_name + 2));
	i = 0;
	ret = add_t_env_with_split_key_value(env[0]);
	if (ret == NULL)
		return (NULL);
	first = ret;
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
	return (first);
}
