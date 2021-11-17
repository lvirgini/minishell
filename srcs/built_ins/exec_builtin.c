/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/17 16:41:40 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_export(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_unset(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_env(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_exit(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

// int	exec_builtin(char **env, t_cmd *cmd, t_builtin *bi)
// {
// 	exec_builtin[bi->cmd](cmd->argv, env, bi);
// 	// printf("%s -> %d\n", cmd->argv[0], bi->cmd);
// 	return (SUCCESS);
// }
