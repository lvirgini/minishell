/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/24 16:55:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_error(int error)
{
	ft_putstr_fd("env", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	if (error == NO_FILE)
		ft_putstr_fd(S_NO_FILE, STDERR_FILENO);
}

void	exec_env(char **arg, char ***env)
{
	int		i;
	char	**envp;

	i = 0;
	envp = *env;
	if (arg[1] != NULL)
	{
		env_error(TOO_MANY_ARGS);
		return ;
	}
	if (envp == NULL || envp[i] == NULL)
		env_error(NO_FILE);
	while (envp && envp[i])
	{
		if (ft_strchr(envp[i], '='))
			printf("%s\n", envp[i]);
		i++;
	}
}
