/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/05 17:10:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Divides the string with the first '=' to separate the key from the value
** and puts it in the new t_env.
**
**		key = all before first '='
**		value = all after first '=' = str + split_location + 1
*/

static t_env	*add_t_env_with_split_key_value(char *str)
{
	int		split_location;
	char	*key;
	char	*value;
	t_env	*ret;

	split_location = ft_strchr_len(str, '=');
	key = ft_strdup_max(str, split_location);
	value = str + split_location + 1;
	ret = add_new_env(key, value);
	free(key);
	return (ret);
}

/*
** get the complete environment send in the main argument
**
**	shell_name = argv[0] + 2 : name of programme after './' 
*/

t_env	**recover_complete_env(char *env[], char *shell_name)
{
	int		i;
	t_env	*current;
	t_env	**my_env;

	my_env = (t_env **)malloc(sizeof(t_env **));
	if (!my_env)
		return (NULL);
	if (!*env)
		return (my_env);
	current = add_t_env_with_split_key_value(env[0]);
	if (current == NULL)
		return (NULL);
	*my_env = current;
	i = 1;
	while (env[i])
	{
		current->next = add_t_env_with_split_key_value(env[i]);
		if (current->next == NULL)
		{
			free_all_t_env(my_env);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	edit_or_add_t_env(my_env, "SHELL", shell_name + 2); // ou "minishell" ou rien ?
	return (my_env);
}
