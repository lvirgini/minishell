/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:34:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/09 16:48:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** split of line env PATH with ':' as delimitor
*/

char	**split_env(char *env)
{
	char	**split;

	if (!env)
		return (NULL);
	split = ft_split(env, ':');
	if (!split)
		perror("split env");
	return (split);
}


static t_bool	is_absolute_path(char **argv)
{
	if (!ft_strncmp(argv[0], "./", 2) || argv[0][0] == '/')
	{
		if (access(argv[0], F_OK) == 0)
			return (true);
	}
	return (false);
}

char	* find_good_path(char **path_env, char *cmd_name)
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
** path of command is needed for execve
** 	check access in absolute path else
** 	'/' is needed between path and command.
** 		ex: PATH=/bin  cmd=ls : test if /bin/ls
** 	search executable with access checking all path
*/

char	*get_path_for_command(t_cmd *cmd, char *path_env[])
{
	char	*slash_cmd;
	char	*path_cmd;

	if (path_env == NULL || is_absolute_path(cmd->argv))
		return (ft_strdup(cmd->argv[0]));
	slash_cmd = ft_strjoin("/", cmd->argv[0]);
	if (!slash_cmd)
	{
		perror("malloc ft_strjoin in get_env");
		return (NULL);
	}
	path_cmd = find_good_path(path_env, slash_cmd);
	free(slash_cmd);
	return (path_cmd);
}

/*
** get the a plit of 'PATH=' env
** add path to all cmd
*/

int	add_path_for_all_cmd(t_cmd *cmd, char *env[])
{
	char	**path_env;

	path_env = split_env(get_env_value(env, "PATH"));
	if (!path_env)
		return (FAILURE);
	while (cmd)
	{
		if (cmd->argv && cmd->argv[0])
			cmd->path = get_path_for_command(cmd, path_env);
		cmd = cmd->next;
	}
	return (SUCCESS);//
}
