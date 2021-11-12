/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:27:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/10 15:43:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_good_path(char **path_env, char *cmd_name)
{
	size_t	i;
	char	*cmd_path;

	i = 0;
	while (path_env[i])
	{
		cmd_path = ft_strjoin(path_env[i], cmd_name);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

/*
** 	'/' is needed between path and command.
** 		ex: PATH=/bin  cmd=ls : test if /bin/ls
** 	search executable with access checking all path
*/

int	get_cmd_path_from_path_env(t_cmd *cmd, char *path_env[])
{
	char	*slash_cmd;

	slash_cmd = ft_strjoin("/", cmd->argv[0]);
	if (!slash_cmd)
	{
		perror("malloc ft_strjoin in get_env");
		return (FAILURE);
	}	
	cmd->path = find_good_path(path_env, slash_cmd);
	free(slash_cmd);
	if (!cmd->path)
	{
		display_error(ERR_CMD_NOT_FOUND, cmd->argv[0]);
		return (FAILURE);
	}
	return (SUCCESS);
}
