/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:27:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/11 17:01:18 by eassouli         ###   ########.fr       */
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
		//close_pipe(cmd->pipe); je crois qu'il faudra check if CMD type == PIPE.
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

int	executer(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;
	t_bi	bi;
	int		std_io[2];

	cmd = *list_cmd;
	save_std_io(std_io);
	while (cmd)
	{
		if (setup_redirections(cmd) == SUCCESS && cmd->argv)
		{
		// check si cest un build in sinon
			if (is_built_in(env, cmd, &bi) == 1)
				printf("C'est le built-in no:%d\n", bi.cmd);
			else if (setup_cmd_path(cmd, env) == SUCCESS && cmd->path)
			{
				if (execute_this_cmd(cmd, env) == FAILURE)
					return (FAILURE);
			}	
		}
		if (get_back_std_io(std_io) == FAILURE)
			return (FAILURE);
		cmd = cmd->next;
	}
	wait_all_process(*list_cmd);
	return (SUCCESS);
}
