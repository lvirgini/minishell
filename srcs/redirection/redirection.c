/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/08 16:03:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
**	INFILE		PIPE 1			PIPE 2			PIPE 3			OUTFILE
**	 --0	1-----------0	1-----------0	1-----------0	1-----
**	|	CD1		|		CD2		|		CD3		|		CD4		|
**
*/

/*
**	input is eclusive for <. not << HERE DOC
**	change standard input by infile
**		O_RDONLY : only reading file
**		O_CLOEXEC : close automatically at the end of execve
** 	if open can't find infile, display error.
*/

int	set_up_input(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		perror(input);
	else if (dup2(fd, IN) == -1)
		perror("dup2 set up input");
	else
	{
//		close(cmd->pipe[IN]);
		return (SUCCESS);
	}
	return (FAILURE);
}

/*
** 	change standard output by outfile (create if not exist)
**		O_CREAT with all option needed : -rw-r--r--
** 		O_TRUNC : if exist 
**	display error and exit.
*/

int	set_up_output(char *output, int type)
{
	int		fd;

	if (type == OUTPUT_REDIRECTION)
		fd = open(output, O_CREAT | O_TRUNC | O_WRONLY | O_SYNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd =  open(output, O_CREAT | O_WRONLY | O_SYNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // A VERIFIER
	if (fd == -1)
		perror(output);
	else if (dup2(fd, OUT) == -1)
		perror("dup2 set up output");
	else
		return (SUCCESS);
	return (FAILURE);
}
