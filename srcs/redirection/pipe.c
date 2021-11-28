/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:43:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 21:52:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	INFILE		PIPE 1			PIPE 2			PIPE 3			OUTFILE
**	 --0	1-----------0	1-----------0	1-----------0	1-----
**	|	CD1		|		CD2		|		CD3		|		CD4		|
**
*/

int	create_pipe(t_cmd *cmd)
{
	if (pipe(cmd->pipe) == -1)
	{
		perror ("pipe in create_pipe()");
		return (FAILURE);
	}
	return (SUCCESS);
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
	return (SUCCESS);
}

/*
**	change standard output by pipe[OUT] of this cmd
*/

static int	setup_pipe_output(t_cmd *cmd)
{
	if (dup2(cmd->pipe[OUT], OUT) == -1)
	{
		perror ("dup2() in setup_pipe_output()");
		return (FAILURE);
	}
	close_fd(cmd->pipe[IN]);
	return (SUCCESS);
}

/*
** if cmd->prev is a PIPE : make pipe[IN] to input
**
** if cmd is a PIPE : make pipe[OUT] to output
*/

int	setup_pipe_redirection(t_cmd *cmd)
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
