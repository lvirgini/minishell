/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:27:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/19 17:28:59 by eassouli         ###   ########.fr       */
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

int	executer(t_cmd **list_cmd, char **env, t_builtin *builtin)
{
	t_cmd					*cmd;
	int						std_io[2];

	cmd = *list_cmd;
	//save_std_io(std_io);
	while (cmd)
	{
		// if (setup_redirections(cmd) == SUCCESS && cmd->argv)
		// {
			// else if (setup_cmd_path(cmd, env) == SUCCESS && cmd->path)
			// {
		if (is_builtin(cmd->argv[0], builtin) == SUCCESS)
		{
			if (exec_builtin(cmd, env, builtin) == FAILURE)
				return (FAILURE);
			save_std_io(std_io);

		}
		else if (execute_this_cmd(cmd, env) == FAILURE)
			return (FAILURE);
		//	}	
	//	}
	//	if (get_back_std_io(std_io) == FAILURE)
		//	return (FAILURE);
		cmd = cmd->next;
	}
	wait_all_process(*list_cmd);
	return (SUCCESS);
}
