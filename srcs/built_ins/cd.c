/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 17:14:47 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

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
	else if (errno == ENOENT || error == NO_FILE)
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
	g_exit.status = 1;
}

void	set_current_pwd(char ***env)
{
	char	*cwd;

	cwd = get_current_dir();
	if (cwd)
	{
		export_join_keyvalue(PWD_KEY, cwd, env);
		free(cwd);
	}
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
		export_join_keyvalue(OLDPWD_KEY, new_old, env);
	}
	return (new_old);
}

char	*cd_path(char **arg, char ***env)
{
	char	*new_old;

	new_old = get_current_dir();
	if (new_old == NULL)
		cd_errors(NO_CWD, arg[1], NULL);
	else if (chdir(arg[1]) == -1)
		cd_errors(0, arg[1], NULL);
	else
		export_join_keyvalue(OLDPWD_KEY, new_old, env);
	return (new_old);
}

void	exec_cd(char **arg, char ***env)
{
	char	*old;

	old = NULL;
	g_exit.status = 0;
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
	if (g_exit.status == 0)
		set_current_pwd(env);
	if (old)
		free(old);
	return ;
}
