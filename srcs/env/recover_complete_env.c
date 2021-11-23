/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_complete_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:28:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 21:16:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_minishell_env(char *env[])
{
	char	**minishell_env;

	minishell_env = list_dup(env);
	if (!minishell_env)
		return (NULL);
	add_env(minishell_env, "SHELL", "minishell");
	return (minishell_env);
}
