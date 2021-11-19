/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 17:28:22 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(char **arg, char **env, t_builtin *builtin)
{
	(void)env;
	(void)builtin;
	(void)arg;
}

void	exec_unset(char **arg, char **env, t_builtin *builtin)
{
	(void)env;
	(void)builtin;
	(void)arg;
}

void	exec_exit(char **arg, char **env, t_builtin *builtin)
{
	(void)env;
	(void)builtin;
	(void)arg;
}

int	exec_builtin(t_cmd *cmd, char **env, t_builtin *builtin)
{
	int						std_io[2];
	static const t_callback	f_builtin[7] = {exec_echo, exec_cd, exec_pwd,
		exec_export, exec_unset, exec_env, exec_exit};

	save_std_io(std_io);
	if (setup_all_redirections(cmd, env) == SUCCESS && cmd->argv)
		f_builtin[builtin->cmd](cmd->argv, env, builtin);
	else
		return (get_back_std_io(std_io));
	return(get_back_std_io(std_io));
}
