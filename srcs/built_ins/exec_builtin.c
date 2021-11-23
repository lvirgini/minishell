/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/23 16:26:47 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(int builtin, char **env, t_cmd *cmd) // comment expand_argv line 55 to hide list of args
{
	int						std_io[2];
	static const t_callback	f_builtin[7] = {exec_echo, exec_cd, exec_pwd,
		exec_export, exec_unset, exec_env, exec_exit};
	save_std_io(std_io);
	if (setup_all_redirections(cmd, env) == SUCCESS && cmd->argv)
		f_builtin[builtin](cmd->argv, env);
	else
		return (get_back_std_io(std_io));
	return (get_back_std_io(std_io));
}
