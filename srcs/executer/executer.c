/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:27:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 14:13:30 by lvirgini         ###   ########.fr       */
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
		close_pipe(cmd->pipe);
		waitpid(cmd->pid, &last_status, 0);
		cmd = cmd->next;
	}
	return (WEXITSTATUS(last_status));
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
	int		builtin;

	cmd = *list_cmd;
	builtin = NOT_BUILTIN;
	while (cmd)
	{
		if (make_heredoc(cmd->heredoc, *env) == FAILURE
			|| (cmd->type == PIPE && create_pipe(cmd) == FAILURE))
			return (FAILURE);
		if (cmd->argv)
			builtin = is_builtin(cmd->argv[0]);
		if (builtin != NOT_BUILTIN)
		{
			if (exec_builtin(builtin, env, cmd) == FAILURE)
				return (FAILURE);
		}
		else if (execute_this_cmd(cmd, *env) == FAILURE)
			return (FAILURE);
		cmd = cmd->next;
	}
	if (builtin != NOT_BUILTIN && (*list_cmd)->next == NULL)
		return (SUCCESS);
	set_exit_status((wait_all_process(*list_cmd)));
	return (SUCCESS);
}
