/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/22 10:43:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pwd_error(int error)
{
	ft_putstr_fd("pwd: ", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
}

void	exec_pwd(char **arg, char **env, t_builtin *builtin)
{
	char	*cwd;
	(void)env;

	if (arg[1] != NULL)
	{
		pwd_error(TOO_MANY_ARGS);
		builtin->error = 1;
		return ;
	}
	cwd = NULL;
	cwd = get_current_dir(cwd);
	printf("%s\n", cwd);
	free(cwd);
}
