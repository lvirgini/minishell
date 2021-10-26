/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:58:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;
	int		env_size;

	env_size = list_strlen(env);
	minishell_env = malloc_list(env_size);
	if (!minishell_env)
		return (NULL);
	if (duplicate_list(minishell_env, env, env_size) == FAILURE)
		return (NULL);
	return (minishell_env);
// add SHELL : shellname
}
