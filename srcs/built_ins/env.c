/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/20 17:36:51 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_error(int error)
{
	if (error == TOO_MANY_ARGS)
		printf("env: %s\n", S_TOO_MANY_ARGS);
}

void	exec_env(char **arg, char **env, t_builtin *builtin)
{
	int	i;

	(void)builtin;
	i = 0;
	if (arg[1] != NULL)
	{
		env_error(TOO_MANY_ARGS);
		return ;
	}
	while (env && env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
