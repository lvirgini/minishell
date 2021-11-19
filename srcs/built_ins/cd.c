/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 13:36:53 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_errors(int error, char **arg)
{
	if (errno == ENOENT) // Autres erreurs ?
		printf("cd: no such file or directory: %s\n", arg[1]);
	else if (errno == ENOTDIR)
		printf("cd: not a directory: %s\n", arg[1]);
	else if (error == TOO_MANY_ARGS)
		printf("cd: %s\n", S_TOO_MANY_ARGS);
	else
		printf("cd: string not in pwd: %s\n", arg[1]);
}

void	exec_cd(char **arg, char **env, t_builtin *bi)
{
	(void)env; // remove
	char	*cwd;

	cwd = NULL;
	if (arg[1] == NULL)
	{
		bi->last = get_current_dir(bi->last);

		if (chdir(bi->home) == -1)
			cd_errors(0, arg); //check si marche
	}
	else if (arg[1] && arg[2] == NULL)
	{
		if (arg[1][0] == '-' && ft_strlen(arg[1]) == 1)
		{
			cwd = get_current_dir(cwd);
			if (bi->last && chdir(bi->last) == -1)
				cd_errors(0, arg);
			if (bi->last)
			{
				printf("%s\n", bi->last);
				free(bi->last);
			}
			else if (cwd)
				printf("%s\n", cwd);
			bi->last = ft_strdup(cwd);
			if (cwd)
				free(cwd);
		}
		else
		{
			bi->last = get_current_dir(bi->last);
			if (chdir(arg[1]) == -1)
				cd_errors(0, arg);
		}
	}
	else if (arg[2] && arg[3])
		cd_errors(TOO_MANY_ARGS, arg);
	else
		cd_errors(0, arg);
}
