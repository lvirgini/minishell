/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:27:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/09 14:37:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	print_error(t_cmd *cmd, int error)////////////////// A REFAIRE EN MIEUX
{
	static char	*str_error[NB_ERROR] = {": command not found\n",
		": permission denied\n"};
	static int	error_exit[NB_ERROR] = {127, 126};

	write(2, "minishell: ", 12);  // getenv nom du shell
	if (cmd->argv && cmd->argv[0])
		write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
	write(2, str_error[error], ft_strlen(str_error[error]));
	close(cmd->pipe[OUT]);
	errno = error_exit[error];
}

/*
** check if commande can be execute by execve
**	if cmd->path exist : access found the executable.
**	if cmd->path doesn't exist : access not found the executable with env
**	make errno to 127 : command not found
*/

int	is_command_executable(t_cmd *cmd)
{
	if (cmd->path == NULL)
	{
		print_error(cmd, ERR_CMD_NOT_FOUND);
		return (FAILURE);
	}
	if (access(cmd->path, X_OK) != 0)
	{
		print_error(cmd, ERR_CMD_NOT_EXECUTABLE);
		return (FAILURE);
	}
	return (SUCCESS);
}

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
		//close_pipe(cmd->pipe);
		cmd = cmd->next;
	}
	return (WEXITSTATUS(last_status));
}

void	close_parent_pipe(t_cmd *cmd)
{
	if (cmd->prev)
		close(cmd->prev->pipe[IN]);
	if (cmd->next)
		close(cmd->pipe[OUT]);
}

int	execute_this_cmd(t_cmd *cmd, char **env)
{
	// check si cest un build in sinon
	cmd->pid = create_child_process(cmd, env);
	close_parent_pipe(cmd);
	return (SUCCESS); //
}


int	executer(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;
	int		std_io[2];

	if (!list_cmd)
		return (FAILURE); // EXIT STATUS ? 
	add_path_for_all_cmd(*list_cmd, env);
	cmd = *list_cmd;
	save_std_io(std_io);
	while (cmd)
	{
		if (setup_redirections(cmd) == SUCCESS && cmd->argv
			&& is_command_executable(cmd) == SUCCESS)
		{
			execute_this_cmd(cmd, env);
		}
		if (get_back_std_io(std_io) == FAILURE)
			return (FAILURE);
		cmd = cmd->next;
	}
	return (wait_all_process(*list_cmd));//
}
