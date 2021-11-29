/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:09:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;
	char	*cwd;

	minishell_env = list_cdup(env, '=');
	export_keyvalue(S_SHELL, &minishell_env);
	unset_key(OLDPWD, &minishell_env);
	cwd = get_current_dir();
	if (cwd)
	{
		export_join_keyvalue(PWD_KEY, cwd, &minishell_env);
		free(cwd);
	}
	export_shlvl(&minishell_env);
	return (minishell_env);
}
