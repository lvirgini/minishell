/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 12:52:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_errors(int error, char *arg, char *path)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS_CD, STDERR_FILENO);
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
	set_exit_status(1);
}

char	*cd_old(char **arg, char ***env)
{
	char	*new_old;
	char	*old;

	new_old = get_current_dir();
	old = get_old_dir(*env);
	if (old && chdir(old) == -1)
	{
		cd_errors(0, arg[1], NULL);
		return (new_old);
	}
	else if (old)
	{
		printf("%s\n", old);
		export_oldpwd(new_old, env);
	}
	return (new_old);
}

char	*cd_path(char **arg, char ***env)
{
	char	*new_old;

	new_old = get_current_dir();
	if (chdir(arg[1]) == -1)
		cd_errors(0, arg[1], NULL);
	else
		export_oldpwd(new_old, env);
	return (new_old);
}

void	exec_cd(char **arg, char ***env)
{
	char	*old;

	set_exit_status(0);
	if (arg[1] == NULL)
		old = cd_home(arg, env);
	else if (arg[1] && arg[2] == NULL)
	{
		if (arg[1][0] == '~')
			old = cd_home(arg, env);
		else if (ft_strcmp(arg[1], "-") == 0)
			old = cd_old(arg, env);
		else
			old = cd_path(arg, env);
	}
	else if (arg[2])
		cd_errors(TOO_MANY_ARGS, arg[1], NULL);
	if (old)
		free(old);
	return ;
}
