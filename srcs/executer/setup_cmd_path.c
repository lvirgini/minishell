/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:34:17 by lvirgini          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/23 21:42:45 by lvirgini         ###   ########.fr       */
=======
/*   Updated: 2021/11/27 13:22:19 by lvirgini         ###   ########.fr       */
>>>>>>> 93c5868c177ee546f4033f7c0a92e432c68cad18
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
<<<<<<< HEAD
** split of line env PATH with ':' as delimitor
*/

static char	**split_path_env(char *env)
{
	char	**split;

	if (!env)
		return (NULL);
	split = ft_split(env, ':');
	if (!split)
		perror("split env");
	return (split);
}

/*
** check if argv[0] is an absolute path and duplicate it in cmd->path.
=======
** check with access X_OK (executable) if file is well executable
*/

static t_bool	is_command_executable(t_cmd *cmd)
{
	if (access(cmd->path, X_OK | R_OK) == 0)
		return (true);
	display_error(ERR_CMD_NOT_EXECUTABLE, cmd->argv[0]);
	return (false);
}

/*
** check if argv[0] is an absolute path or relative path and duplicate it
**	in cmd->path.
>>>>>>> 93c5868c177ee546f4033f7c0a92e432c68cad18
*/

static t_bool	is_relative_or_absolute_path(char *argv)
{
	if (ft_strchr(argv, '/') || !ft_strcmp(argv, ".") || !ft_strcmp(argv, ".."))
		return (true);
	return (false);
}

t_bool	add_absolute_or_relative_path(t_cmd *cmd, char *argv)
{
	int	fd;

	fd = open(argv, __O_DIRECTORY);
	if (fd != -1)
	{	
		close(fd);
		display_error(ERR_IS_A_DIRECTORY, argv);
		return (FAILURE);
	}
	if (access(argv, F_OK) == 0)
	{
		cmd->path = ft_strdup(argv);
		if (!cmd->path)
		{
			perror("malloc in add_absolute_path");
			return (FAILURE);
		}
		return (SUCCESS);
	}
	display_error(ERR_ABSOLUTE_PATH_NOT_FOUND, argv);
	return (FAILURE);
}

/*
** if no cmd return SUCCESS because it can be only redirections.
**	- check absolute path
**
** 	path of command is needed for execve
**	- find executable file path with split env "PATH" with ':'.
** 	- check if executable file has permission to be executed.
*/

t_bool	argv_is_empty(char **argv)
{
	if (argv[0][0] == '\0')
	{
		display_error(ERR_CMD_NOT_FOUND, argv[0]);
		return (true);
	}
	return (false);
}

int	setup_cmd_path(t_cmd *cmd, char **env)
{
	if (!cmd->argv || !cmd->argv[0] || argv_is_empty(cmd->argv))
		return (FAILURE);
	if (is_relative_or_absolute_path(cmd->argv[0]))
	{
		if (add_absolute_or_relative_path(cmd, cmd->argv[0]) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (add_path_with_envpath(cmd, env) == FAILURE)
			return (FAILURE);
	}
	if (is_command_executable(cmd) == true)
		return (SUCCESS);
	return (FAILURE);
}
