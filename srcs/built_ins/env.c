/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 11:26:22 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_error(int error)
{
	ft_putstr_fd("env :", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	if (error == NO_FILE)
		ft_putstr_fd(S_NO_FILE, STDERR_FILENO);
}

int		is_key_value(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
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
	if (env == NULL || env[i] == NULL)
		env_error(NO_FILE);
	while (env && env[i])
	{
		if (is_key_value(env[i]) == 1)
			printf("%s\n", env[i]);
		i++;
	}
}
