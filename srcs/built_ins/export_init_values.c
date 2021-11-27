/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_init_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:00 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/27 15:28:34 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_keyvalue(char *str, char ***env)
{
	static char	*keyvalue[3];

	keyvalue[1] = str;
	keyvalue[2] = NULL;
	exec_export(keyvalue, env);
}

void	export_join_keyvalue(char *key, char *value, char ***env)
{
	static char	*oldpwd[3];

	oldpwd[1] = ft_strjoin(key, value);
	if (oldpwd[1] == NULL)
		return ;
	oldpwd[2] = NULL;
	exec_export(oldpwd, env);
	free(oldpwd[1]);
}

static char	*new_nb(char *value)
{
	int		nb;
	char	*new_nb_value;

	nb = ft_atoi(value);
	new_nb_value = ft_itoa(nb + 1);
	return (new_nb_value);
}

void	export_shlvl(char ***env)
{
	char		*value;
	char		*new_value;
	static char	*shlvl[3];

	shlvl[2] = NULL;
	value = get_env_value(*env, SHLVL);
	new_value = new_nb(value);
	if (value == NULL || new_value == NULL)
	{
		shlvl[1] = SHLVL1_KEY;
		exec_export(shlvl, env);
		return ;
	}
	shlvl[1] = ft_strjoin(SHLVL_KEY, new_value);
	if (shlvl[1])
	{
		exec_export(shlvl, env);
		free(shlvl[1]);
	}
	free(new_value);
}

void	unset_key(char *key, char ***env)
{
	static char	*oldpwd[3];

	oldpwd[1] = key;
	oldpwd[2] = NULL;
	exec_unset(oldpwd, env);
}
