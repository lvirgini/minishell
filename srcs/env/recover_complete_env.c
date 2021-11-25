/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 09:54:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;
//	int		env_size;

	//env_size = listlen(env);
	//minishell_env = malloc_list(env_size);
	minishell_env = list_cdup(env, '=');
	if (!minishell_env)
		return (NULL);
	export_shell(&minishell_env);
	export_shlvl(&minishell_env);
	unset_oldpwd(&minishell_env);
//	if (list_ndup(minishell_env, env, env_size) == FAILURE)//
//		return (NULL);
	return (minishell_env);
}
