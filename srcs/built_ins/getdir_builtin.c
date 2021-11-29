/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:45:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 17:02:57 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

char	*get_home_dir(char **env)
{
	char	*home;
	char	*tmp;

	tmp = get_env_value(env, "HOME");
	if (tmp == NULL)
	{
		ft_putstr_fd(S_NO_HOME, STDERR_FILENO);
		g_exit.status = 1;
		return (NULL);
	}
	home = ft_strjoin(tmp, "/");
	if (home == NULL)
		perror("ft_strjoin in get_home_dir");
	return (home);
}

char	*get_current_dir(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	return (cwd);
}

char	*get_old_dir(char **env)
{
	char	*old;

	old = get_env_value(env, "OLDPWD");
	if (old == NULL)
	{
		ft_putstr_fd(S_NO_OLDPWD, STDERR_FILENO);
		g_exit.status = 1;
	}
	return (old);
}
