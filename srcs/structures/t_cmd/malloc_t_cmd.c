/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_t_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:40:55 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 19:22:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** malloc a t_cmd
*/

t_cmd	*malloc_t_cmd(t_cmd *prev)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(t_cmd));
	cmd->prev = prev;
	return (cmd);
}

/*
** malloc the list of cmd
*/

t_cmd	**malloc_list_t_cmd(void)
{
	t_cmd **cmd;

	cmd = (t_cmd **)malloc(sizeof(t_cmd *));
	if (!cmd)
		return (NULL);
	return (cmd);
}
