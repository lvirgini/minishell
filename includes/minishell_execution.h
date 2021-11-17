/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/17 16:34:31 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTION_H
# define MINISHELL_EXECUTION_H

# include "minishell.h"

typedef struct s_builtin t_builtin;

int		executer(t_cmd **cmd, char *env[], t_builtin *bi);
int		add_path_for_all_cmd(t_cmd *cmd, char *env[]);
pid_t	create_child_process(t_cmd *cmd, char *env[]);

/*
** find path for execve.
*/

int		setup_cmd_path(t_cmd *cmd, char **env);
int		get_cmd_path_from_path_env(t_cmd *cmd, char *path_env[]);

#endif
