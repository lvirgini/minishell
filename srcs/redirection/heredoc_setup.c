/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:40:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 15:55:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** if the heredoc is the last one (priority 0 because no input behind)
**	create the pipe to write on the output of the pipe and dup2 to match 
**	the input of the pipe.
*/

int	setup_heredoc_input(t_hdoc *heredoc)
{
	int		pipefd[2];

	while (heredoc)
	{
		if (heredoc->priority == 0)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe in setup_heredoc()");
				return (FAILURE);
			}
			if (dup2(pipefd[IN], IN))
			{
				perror("dup2 in setup_heredo_input()");
				return (FAILURE);
			}
			print_list_fd(heredoc->data, pipefd[OUT]);
			close_fd(pipefd[OUT]);
			return (SUCCESS);
		}
		heredoc = heredoc->next;
	}
	return (SUCCESS);
}