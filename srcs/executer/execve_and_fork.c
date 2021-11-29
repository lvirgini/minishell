/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_and_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:19:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 14:10:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Use execve() for executing this cmd.
** if error (execve exit alway so it's all after execve) 
**	print execve error return -1 for exit minishell
*/

static int	execve_this_command(t_cmd *cmd, char *env[])
{
	int		ret;
	char	**clean_env;

	clean_env = make_minishell_env(env);
	if (clean_env == NULL)
		return (-1);
	free_list(env);
	env = NULL;
	ret = execve(cmd->path, cmd->argv, clean_env);
	perror("execve");
	errno = ret;
	return (-1);
}

/*
** create a child processus with fork()
** in CHILD :
**		setup all redirections
**		setup the command path
**		execute with execve this command
**		 If a problem occurs, the exit status is no longer 0.
**		return -1 to free up all minishell mallocs and stop this CHILD properly.
** in PARENT : 
**		return child pid;
*/

pid_t	create_child_process(t_cmd *cmd, char *env[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (setup_all_redirections(cmd, env) == SUCCESS && listlen(cmd->argv)
			&& setup_cmd_path(cmd, env) == SUCCESS && cmd->path)
			return (execve_this_command(cmd, env));
		return (-1);
	}
	return (pid);
}
