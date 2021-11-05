/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/05 08:09:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	**make_minishell_env(char *env[])
{
	char	**minishell_env;
//	int		env_size;

	//env_size = listlen(env);
	//minishell_env = malloc_list(env_size);
	minishell_env = list_dup(env);
	if (!minishell_env)
		return (NULL);
//	if (list_ndup(minishell_env, env, env_size) == FAILURE)//
//		return (NULL);
	return (minishell_env);
// add SHELL : shellname
}
