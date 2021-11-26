/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 13:42:48 by lvirgini         ###   ########.fr       */
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
