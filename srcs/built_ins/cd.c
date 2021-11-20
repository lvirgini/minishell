/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/20 17:45:15 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_errors(int error, char **arg, char *path)
{
	if (error == TOO_MANY_ARGS)
		printf("cd: %s\n", S_TOO_MANY_ARGS);
	else if (errno == ENOENT && path == NULL) // Autres erreurs ?
		printf("cd: %s: No such file or directory\n", arg[1]);
	else if (errno == ENOTDIR && path == NULL)
		printf("cd: %s: Not a directory\n", arg[1]);
	else if (errno == ENOENT) // Autres erreurs ?
		printf("cd: %s: No such file or directory\n", path);
	else if (errno == ENOTDIR)
		printf("cd: %s: Not a directory\n", path);
}

void	cd_home(char **arg, t_builtin *builtin)
{
	char	*path;

	path = NULL;
	if (builtin->home == NULL)
		return ;
	builtin->last = get_current_dir(builtin->last);
	if (ft_strcmp(arg[1], "~") == 0)
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
	if (chdir(arg[1]) == -1) // revoir le comportement
		cd_errors(0, arg, path); //check si marche
}

void	cd_last(char **arg, t_builtin *builtin)
{
	char	*cwd;

	cwd = NULL;
	cwd = get_current_dir(cwd);
	if (builtin->last && chdir(builtin->last) == -1)
		cd_errors(0, arg, NULL);
	if (builtin->last)
	{
		printf("%s\n", builtin->last);
		free(builtin->last);
	}
	else if (cwd)
		printf("%s\n", cwd);
	builtin->last = ft_strdup(cwd);
	if (cwd)
		free(cwd);
}

void	cd_path(char **arg, t_builtin *builtin)
{
	builtin->last = get_current_dir(builtin->last);
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
			cd_last(arg, builtin);
		else
			cd_path(arg, builtin);
	}
	else if (arg[2])
		cd_errors(TOO_MANY_ARGS, arg, NULL);
}
