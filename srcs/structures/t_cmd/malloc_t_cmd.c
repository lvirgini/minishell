/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_t_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:40:55 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 18:01:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** malloc a t_cmd
*/

t_cmd	*malloc_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(t_cmd));
	cmd->pipe[0] = -1;
	cmd->pipe[1] = -1;
	return (cmd);
}

/*
** malloc the list of cmd
*/

t_cmd	**malloc_list_cmd(void)
{
	t_cmd	**list_cmd;

	list_cmd = (t_cmd **)malloc(sizeof(t_cmd *));
	if (!list_cmd)
	{
		perror("malloc_list_cmd()");
		return (NULL);
	}
	*list_cmd = NULL;
	return (list_cmd);
}
