/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 14:20:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTION_H
# define MINISHELL_EXECUTION_H

# include "minishell.h"

int		executer(t_cmd **cmd, char *env[]);
int		add_path_for_all_cmd(t_cmd *cmd, char *env[]);
pid_t	create_child_process(t_cmd *cmd, char *env[]);

/*
** find path for execve.
*/

int		setup_cmd_path(t_cmd *cmd, char **env);
t_bool	add_absolute_path(t_cmd *cmd, char *argv);
t_bool	add_path_with_envpath(t_cmd *cmd, char **env);
t_bool	add_relative_path(t_cmd *cmd, char *argv);

#endif
