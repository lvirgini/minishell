/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 10:12:45 by eassouli         ###   ########.fr       */
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
			expand_argv(cmd, env);
			if (!cmd->argv)
				return (FAILURE);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
