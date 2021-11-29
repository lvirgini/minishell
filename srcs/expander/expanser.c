/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 16:52:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;

	if (!list_cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
		if (cmd->argv)
		{
			if (expand_argv(cmd, env) == FAILURE)
				return (FAILURE);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
