/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/26 08:28:08 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pwd_error(int error)
{
	ft_putstr_fd("pwd", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	set_exit_status(1);
}

void	exec_pwd(char **arg, char ***env)
{
	char	*cwd;

	(void)env;
	set_exit_status(0);
	if (arg[1] != NULL)
	{
		pwd_error(TOO_MANY_ARGS);
		return ;
	}
	cwd = get_current_dir();
	printf("%s\n", cwd);
	if (cwd)
		free(cwd);
}
