/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:45:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 17:02:10 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home_dir(char **env)
{
	char	*home;
	char	*tmp;

	tmp = get_env_value(env, "HOME");
	if (tmp == NULL)
	{
		ft_putstr_fd(S_NO_HOME, STDERR_FILENO);
		return (NULL);
	}
	home = ft_strjoin(tmp, "/"); // secure malloc ? //move to original function
	if (home == NULL)
		perror("ft_strjoin in get_home_dir");
	return (home);
}

char	*get_current_dir(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0); //join avec OLDPWD et export et return error OLDPWD not set
	if (cwd == NULL)
		perror("getcwd");
	return (cwd);
}

char	*get_old_dir(char **env) // Set values old dir
{
	char	*old;

	old = get_env_value(env, "OLDPWD");
	if (old == NULL)
		ft_putstr_fd(S_NO_OLDPWD, STDERR_FILENO);
	return (old);
}
