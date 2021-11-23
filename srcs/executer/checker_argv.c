/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:41:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 21:44:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check with access X_OK (executable) if file is well executable
*/

t_bool	is_command_executable(t_cmd *cmd)
{
	if (access(cmd->path, X_OK) == 0)
		return (true);
	display_error(ERR_CMD_NOT_EXECUTABLE, cmd->argv[0]);
	return (false);
}
