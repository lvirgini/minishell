/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/26 11:05:58 by eassouli         ###   ########.fr       */
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
	close_fd(pipe[OUT]);
}

void	close_parent_pipe(t_cmd *cmd)
{
	if (cmd->next && cmd->type == PIPE)
		close_fd(cmd->pipe[OUT]);
}
