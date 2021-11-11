/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:21:39 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/11 17:00:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_built_ins(t_bi *bi)
{
	bi->cmd = -1;
	bi->error = -1;
}

int	is_built_in(char **env, t_cmd *cmd, t_bi *bi)
{
	(void)env;
	(void)bi;
	int	i;

	i = 0;
	init_built_ins(bi);
	if (ft_strncmp(cmd->argv[0], S_ECHO, 4) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 4)
			bi->cmd = CMD_ECHO;
	}
	else if (ft_strncmp(cmd->argv[0], S_CD, 2) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 2)
			bi->cmd = CMD_CD;
	}
	else if (ft_strncmp(cmd->argv[0], S_PWD, 3) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 3)
			bi->cmd = CMD_PWD;
	}
	else if (ft_strncmp(cmd->argv[0], S_EXPORT, 6) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 6)
			bi->cmd = CMD_EXPORT;
	}
	else if (ft_strncmp(cmd->argv[0], S_UNSET, 5) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 5)
			bi->cmd = CMD_UNSET;
	}
	else if (ft_strncmp(cmd->argv[0], S_ENV, 3) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 3)
			bi->cmd = CMD_ENV;
	}
	else if (ft_strncmp(cmd->argv[0], S_EXIT, 4) == 0)
	{
		while (cmd->argv[0][i])
			i++;
		if (i == 4)
			bi->cmd = CMD_EXIT;
	}
	if (bi->cmd != -1)
		return (1);
	return (0);
}