/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 18:32:25 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

/*
** Print an error if there are more than 1 argument
** and an error if getcwd can't find actual directory
*/

static void	pwd_error(int error)
{
	ft_putstr_fd("pwd", STDERR_FILENO);
	if (error == NO_CWD)
		ft_putstr_fd(S_NO_CWD, STDERR_FILENO);
	g_exit.status = 1;
}

void	exec_pwd(char **arg, char ***env)
{
	char	*cwd;

	(void)arg;
	(void)env;
	g_exit.status = 0;
	cwd = get_current_dir();
	if (cwd)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
		pwd_error(NO_CWD);
}
