/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_and_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:19:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:43:56 by lvirgini         ###   ########.fr       */
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
	int	ret;

	ret = execve(cmd->path, cmd->argv, env);
	perror("execve");
	errno = ret;
	return (-1);
}

/*
** create a child processus with fork()
** in CHILD : 
**		execute with execve this command
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
