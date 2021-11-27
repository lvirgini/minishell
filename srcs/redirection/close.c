/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 16:17:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(int fd)
{
	if (fd != -1)
		close(fd);
}

void	close_pipe(int pipe[2])
{
	close_fd(pipe[IN]);
	pipe[IN] = -1;
	close_fd(pipe[OUT]);
	pipe[OUT] = -1;
}

void	close_parent_pipe(t_cmd *cmd)
{
	if (cmd->next && cmd->type == PIPE)
		close_fd(cmd->pipe[OUT]);
	if (cmd->prev && cmd->type == PIPE)
		close_fd(cmd->prev->pipe[IN]);
}
