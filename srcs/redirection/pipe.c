/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:43:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 12:18:16 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	INFILE		PIPE 1			PIPE 2			PIPE 3			OUTFILE
**	 --0	1-----------0	1-----------0	1-----------0	1-----
**	|	CD1		|		CD2		|		CD3		|		CD4		|
**
*/

void	close_pipe(int pipe[2])
{
	close(pipe[IN]);
	close(pipe[OUT]);
}

/*
**	change standard input by pipe[IN] of cmd prev
*/

static int	setup_pipe_input(t_cmd *cmd)
{
	if (dup2(cmd->prev->pipe[IN], IN) == -1)
	{
		perror ("dup2() in setup_pipe_input()");
		return (FAILURE);
	}
	close(cmd->prev->pipe[OUT]);
	return (SUCCESS);
}

/*
**	change standard output by pipe[OUT] of this cmd
*/

static int	setup_pipe_output(t_cmd *cmd)
{
	//fprintf(stderr, "PIPE: %d:%d\n", cmd->pipe[IN],cmd->pipe[OUT]);
	if (dup2(cmd->pipe[OUT], OUT) == -1)
	{
		perror ("dup2() in setup_pipe_output()");
		return (FAILURE);
	}
	close(cmd->pipe[IN]);
	return (SUCCESS);
}

/*
** if cmd->prev is a PIPE : make pipe[IN] to input
**
** if cmd is a PIPE : make pipe[OUT] to output
*/

int	make_pipe_redirection(t_cmd *cmd)
{
	if (cmd->prev && cmd->prev->type == PIPE)
	{
		if (setup_pipe_input(cmd) == FAILURE)
			return (FAILURE);
	}
	if (cmd->type == PIPE)
	{	
		if (setup_pipe_output(cmd) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
