/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/27 18:02:12 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** create a child processus with fork()
** in CHILD : 
**		execute with execve this command
** in PARENT : 
**		return child pid;
*/

pid_t	create_child_builtin(char **arg, char ***env, t_callback f_builtin, t_cmd *cmd)
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
		if (setup_all_redirections(cmd, *env) == SUCCESS)
		{
			f_builtin(arg, env);
			close_pipe(cmd->pipe);
			//  dprintf(2, "exit status %d\n", get_exit_status());
		}
		return (-1);
	}
	return (pid);
}

int	exec_builtin(int builtin, char ***env, t_cmd *cmd) // comment expand_argv line 55 to hide list of args
{
	int						std_io[2];
	static const t_callback	f_builtin[7] = {exec_echo, exec_cd, exec_pwd,
		exec_export, exec_unset, exec_env, exec_exit};

	signal(SIGINT, handle_cmd);
	signal(SIGQUIT, handle_cmd);
	if (cmd->type == PIPE || (cmd->prev && cmd->prev->type == PIPE))
	{
		cmd->pid = create_child_builtin(cmd->argv, env, f_builtin[builtin], cmd);
		close_parent_pipe(cmd);
		if (cmd->pid == -1)
			return (FAILURE);
	}
	else
	{
		save_std_io(std_io);
		if (setup_all_redirections(cmd, *env) == SUCCESS)
			f_builtin[builtin](cmd->argv, env);
		return (get_back_std_io(std_io));
	}
	return (SUCCESS);
}

/*
int	exec_builtin(int builtin, char ***env, t_cmd *cmd) // comment expand_argv line 55 to hide list of args
{
	int						std_io[2];
	static const t_callback	f_builtin[7] = {exec_echo, exec_cd, exec_pwd,
		exec_export, exec_unset, exec_env, exec_exit};

	save_std_io(std_io);
	if (setup_all_redirections(cmd, *env) == SUCCESS && cmd->argv)
	{
		if (cmd->type == PIPE)
		{
			cmd->pid = create_child_builtin(cmd->argv, env, f_builtin[builtin]);
			close_pipe(cmd->pipe);
			if (cmd->pid == -1)
				return (FAILURE);
		}
		else
			f_builtin[builtin](cmd->argv, env);
	}
	return (get_back_std_io(std_io));
	// return (SUCCESS);
}
*/