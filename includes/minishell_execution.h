/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/08 17:30:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTION_H
# define MINISHELL_EXECUTION_H

# include "minishell.h"

int		executer(t_cmd **cmd, char *env[]);
int		add_path_for_all_cmd(t_cmd *cmd, char *env[]);
pid_t	create_child_process(t_cmd *cmd, char *env[]);

#endif
