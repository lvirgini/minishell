/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:45:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/20 17:47:51 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home_dir(void)
{
	char	*home;
	char	*tmp;

	tmp = getenv("HOME");
	if (tmp == NULL)
		perror("getenv");
	home = ft_strjoin(tmp, "/"); // secure malloc ?
	return (home);
}

char	*get_current_dir(char *last_dir)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
		perror("getcwd");
	else
	{
		if (last_dir)
			free(last_dir);
		last_dir = cwd;
	}
	return (last_dir);
}
