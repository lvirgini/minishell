/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:45:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 14:49:04 by eassouli         ###   ########.fr       */
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
		perror("cd: HOME not set\n");
		return (NULL);
	}
	home = ft_strjoin(tmp, "/"); // secure malloc ?
	if (home == NULL)
		perror("ft_strjoin in get_home_dir");
	return (home);
}

char	*get_current_dir()
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0); //join avec OLDPWD et export et return error OLDPWD not set
	if (cwd == NULL)
		perror("getcwd");
	return (cwd);
}

char	*get_old_dir(char **env)
{
	tmp = get_env_value(env, "OLDPWD");
}