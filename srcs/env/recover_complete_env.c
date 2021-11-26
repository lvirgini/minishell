/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 18:12:58 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;

	minishell_env = list_cdup(env, '=');
	export_shell(&minishell_env);
	export_shlvl(&minishell_env);
	//export pwd
	//export if path introuvable path=/bin
	unset_oldpwd(&minishell_env);
	return (minishell_env);
}
