/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:40 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/24 19:50:49 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home_plus(char *home, char *new_old, char *arg, char ***env)
{
	char	*path;

	path = NULL;
	path = ft_strjoin(home, arg + 2);
	if (chdir(path) == -1)
		cd_errors(0, arg, path);
	else
		export_oldpwd(new_old, env);
	if (path)
		free (path);
}

void	cd_home(char **arg, char ***env)
{
	char	*home;
	char	*new_old;

	home = get_home_dir(*env);
	new_old = get_current_dir();
	if (home && (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0))
	{
		if (chdir(home) == -1)
			cd_errors(0, arg[1], NULL); //check si marche
		else
			export_oldpwd(new_old, env);
	}
	else if (home && arg[1][1] == '/')
		cd_home_plus(home, new_old, arg[1], env);
	else if (chdir(arg[1]) == -1) // revoir le comportement
		cd_errors(0, arg[1], NULL);
	else
		export_oldpwd(new_old, env); // A faire ?
}
