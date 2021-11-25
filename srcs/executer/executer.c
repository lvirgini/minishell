/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:27:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 18:51:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** PARENT : wait all processus terminated
**	make errno of PARENT like the last child processus.
** 	return status of last command.
*/

int	wait_all_process(t_cmd *cmd)
{
	int	last_status;

	while (cmd)
	{
		last_status = 0;
		waitpid(cmd->pid, &last_status, 0);
		cmd = cmd->next;
	}
	return (WEXITSTATUS(last_status));
}

void	close_parent_pipe(t_cmd *cmd)
{
	if (cmd->prev && cmd->prev->type == PIPE)
		close(cmd->prev->pipe[IN]);
	if (cmd->next && cmd->type == PIPE)
		close(cmd->pipe[OUT]);
}

int	execute_this_cmd(t_cmd *cmd, char **env)
{
	cmd->pid = create_child_process(cmd, env);
	close_parent_pipe(cmd);
	if (cmd->pid == -1)
		return (FAILURE);
	return (SUCCESS);
}

int	executer(t_cmd **list_cmd, char ***env)
{
	t_cmd	*cmd;
	int		std_io[2];
	int		builtin;

	cmd = *list_cmd;
	while (cmd)
	{
		if (cmd->type == PIPE && create_pipe(cmd) == FAILURE)
			return (-1);
		builtin = is_builtin(cmd->argv[0]);
		if (builtin != NOT_BUILTIN)
		{
			// save_std_io(std_io);
			if (exec_builtin(builtin, env, cmd) == FAILURE)
				return (FAILURE);
		//	close_parent_pipe(cmd);
			// get_back_std_io(std_io);
			// exit si dans pipe
		}
		else if (execute_this_cmd(cmd, *env) == FAILURE)
			return (FAILURE);
		cmd = cmd->next;
	}
	if (builtin == NOT_BUILTIN)
		set_exit_status((wait_all_process(*list_cmd)));
	if (builtin != NOT_BUILTIN)
		set_exit_status((wait_all_process(*list_cmd)));
	return (SUCCESS);
}
