/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 16:11:20 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pwd_error(int error)
{
	if (error == TOO_MANY_ARGS)
		printf("pwd: %s\n", S_TOO_MANY_ARGS);
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
