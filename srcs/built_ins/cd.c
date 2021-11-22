/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 14:43:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_errors(int error, char **arg, char *path)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	else if (errno == EACCES)
	{
		ft_putstr_fd(arg[1], STDERR_FILENO);
		ft_putstr_fd(S_PERM, STDERR_FILENO);
	}
	else if (errno == ENOENT) // Autres erreurs ?
	{
		if (path == NULL)
			ft_putstr_fd(arg[1], STDERR_FILENO);
		else
			ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(S_NO_FILE, STDERR_FILENO);
	}
	else if (errno == ENOTDIR)
	{
		if (path == NULL)
			ft_putstr_fd(arg[1], STDERR_FILENO);
		else
			ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(S_NO_DIR, STDERR_FILENO);
	}
}

void	cd_home(char **arg, t_builtin *builtin) //recheck home a chaque fois
{
	char	*path;

	path = NULL;
	if (builtin->home == NULL)
		return ;
	builtin->old = get_current_dir(builtin->old);
	
	if (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0)
	{
		if (chdir(builtin->home) == -1)
			cd_errors(0, arg, path); //check si marche
		return ;
	}
	else if (arg[1][1] == '/')
	{
		path = ft_strjoin(builtin->home, arg[1] + 2);
		if (chdir(path) == -1)
			cd_errors(0, arg, path); //check si marche
		if (path)
			free (path);
		return ;
	}
	else if (chdir(arg[1]) == -1) // revoir le comportement
		cd_errors(0, arg, path); //check si marche
}

void	cd_old(char **arg, t_builtin *builtin) //Faire avec export
{
	char	*cwd;

	cwd = NULL;
	cwd = get_current_dir(cwd);
	if (builtin->old && chdir(builtin->old) == -1)
		cd_errors(0, arg, NULL);
	if (builtin->old)
	{
		printf("%s\n", builtin->old);
		free(builtin->old);
	}
	else if (cwd)
		printf("%s\n", cwd);
	builtin->old = ft_strdup(cwd);
	if (cwd)
		free(cwd);
}

void	cd_path(char **arg, t_builtin *builtin)
{
	builtin->old = get_current_dir(builtin->old);
	if (chdir(arg[1]) == -1)
		cd_errors(0, arg, NULL);
}

void	exec_cd(char **arg, char **env, t_builtin *builtin)
{
	(void)env; // remove
	if (arg[1] == NULL)
		cd_home(arg, builtin);
	else if (arg[1] && arg[2] == NULL)
	{
		if (arg[1][0] == '~')
			cd_home(arg, builtin);
		else if (ft_strcmp(arg[1], "-") == 0)
			cd_old(arg, builtin);
		else
			cd_path(arg, builtin);
	}
	else if (arg[2])
		cd_errors(TOO_MANY_ARGS, arg, NULL);
}
