/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:34:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 19:22:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
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
** check with access X_OK (executable) if file is well executable
*/

static t_bool	is_command_executable(t_cmd *cmd)
{
	if (access(cmd->path, X_OK) == 0)
		return (true);
	display_error(ERR_CMD_NOT_EXECUTABLE, cmd->argv[0]);
	return (false);
}

/*
** check if argv[0] is an absolute path and duplicate it in cmd->path.
*/

static t_bool	is_absolute_path(char *argv)
{
	if (!ft_strncmp(argv, "./", 2) || argv[0] == '/')
		return (true);
	return (false);
}

static t_bool	get_absolute_path(t_cmd *cmd, char *argv)
{
	if (access(argv, F_OK) == 0)
	{
		cmd->path = ft_strdup(argv);
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
	char	**path_env;

	if (!cmd->argv || !cmd->argv[0] || argv_is_empty(cmd->argv))
		return (FAILURE);
	if (is_absolute_path(cmd->argv[0]) == true)
	{
		if (get_absolute_path(cmd, cmd->argv[0]) == FAILURE)
			return (FAILURE);
	}
	else
	{
		path_env = split_path_env(get_env_value(env, "PATH"));
		if (!path_env || get_cmd_path_from_path_env(cmd, path_env) == FAILURE)
		{
			free_list(path_env);
			return (FAILURE);
		}	
		free_list(path_env);
	}
	if (is_command_executable(cmd) == true)
		return (SUCCESS);
	return (FAILURE);
}
