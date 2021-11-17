/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:44:28 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/17 15:46:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_errors(char **arg)
{
	if (errno == ENOENT) // Autres erreurs ?
		printf("cd: no such file or directory: %s\n", arg[1]);
	else if (errno == ENOTDIR)
		printf("cd: not a directory: %s\n", arg[1]);
}

void	exec_cd(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
	char	*cwd;

	cwd = NULL;
	if (arg[1] == NULL)
	{
		bi->last = get_current_dir(bi->last);

		if (chdir(bi->home) == -1)
			cd_errors(arg); //check si marhce
	}
	else if (arg[1] && arg[2] == NULL) //faire cd -
	{
		if (arg[1][0] == '-' && ft_strlen(arg[1]) == 1)
		{
			cwd = get_current_dir(cwd);
			if (bi->last && chdir(bi->last) == -1)
				cd_errors(arg);
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
				cd_errors(arg);
		}
	}
	else
		printf("cd: string not in pwd: %s\n", arg[1]);
}

void	exec_pwd(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	char	*cwd;
	
	if (arg[1] != NULL)
	{
		printf("pwd: too many arguments\n");
		bi->error = 1;
		return ;
	}
	cwd = NULL;
	cwd = get_current_dir(cwd);
	printf("%s\n", cwd);
	free(cwd);
}
