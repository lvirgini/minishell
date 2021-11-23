/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/23 09:01:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_errors(int error, char *arg, char *path)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	else if (errno == EACCES)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_PERM, STDERR_FILENO);
	}
	else if (errno == ENOENT) // Autres erreurs ?
	{
		if (path == NULL)
			ft_putstr_fd(arg, STDERR_FILENO);
		else
			ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(S_NO_FILE, STDERR_FILENO);
	}
	else if (errno == ENOTDIR)
	{
		if (path == NULL)
			ft_putstr_fd(arg, STDERR_FILENO);
		else
			ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(S_NO_DIR, STDERR_FILENO);
	}
}

void	cd_home(char **arg, char **env)
{
	char	*path;
	char	*home;

	path = NULL;
	home = get_home_dir(env);
	if (home && (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0))
	{
		if (chdir(home) == -1)
			cd_errors(0, arg[1], path); //check si marche
		return ;
	}
	else if (home && arg[1][1] == '/')
	{
		path = ft_strjoin(home, arg[1] + 2);
		if (chdir(path) == -1)
			cd_errors(0, arg[1], path);
		if (path)
			free (path);
		return ;
	}
	else if (chdir(arg[1]) == -1) // revoir le comportement
		cd_errors(0, arg[1], NULL);
}

void	cd_old(char **arg, char **env)
{
	char	*new_old;
	char	*old;

	new_old = get_current_dir();
	old = get_old_dir(env);
	if (old && chdir(old) == -1)
	{
		cd_errors(0, arg[1], NULL);
		return ;
	}
	printf("%s\n", old);
	exec_export(&new_old, env);
}

void	cd_path(char **arg, char **env)
{
	char	*old;

	old = get_current_dir();
	exec_export(&old, env); //change oldpwd
	if (chdir(arg[1]) == -1)
		cd_errors(0, arg[1], NULL);
}

void	exec_cd(char **arg, char **env)
{
	if (arg[1] == NULL)
		cd_home(arg, env);
	else if (arg[1] && arg[2] == NULL)
	{
		if (arg[1][0] == '~')
			cd_home(arg, env);
		else if (ft_strcmp(arg[1], "-") == 0)
			cd_old(arg, env);
		else
			cd_path(arg, env);
	}
	else if (arg[2])
		cd_errors(TOO_MANY_ARGS, arg[1], NULL);
}
