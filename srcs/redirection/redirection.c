/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:32:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/09 14:45:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	input is eclusive for <. not << HERE DOC
**	change standard input by infile
**		O_RDONLY : only reading file
**		O_CLOEXEC : close automatically at the end of execve
** 	if open can't find infile, display error.
*/

static int	open_input(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY |__O_CLOEXEC);
	if (fd == -1)
		perror(input);
	else if (dup2(fd, IN) == -1)
		perror("dup2 set up input");
	else
		return (SUCCESS);
	return (FAILURE);
}

int	setup_inputs(t_redir *input)
{
	int	fd;

	while (input)
	{
		if ((fd = open_input(input->filename)) == FAILURE)
			return (FAILURE);
		input = input->next;
	}
	return (SUCCESS);
}

/*
** 	change standard output by outfile (create if not exist)
** flags:
**		O_CREAT with all option needed : -rw-r--r--
** 		O_WRONLY : write and read
**
** for OUTPUT REDIRECTION > :
**		O_TRUNC : clear file if he exist.
** for APPEND >> :
		O_APPEND : for write at the end of the file.
**	display error if open problem.
*/

static int	open_output(char *output, int type)
{
	int		fd;

	if (type == OUTPUT_REDIRECTION)
		fd = open(output, O_CREAT | O_TRUNC | O_WRONLY | O_SYNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd = open(output, O_CREAT | O_APPEND | O_WRONLY | O_SYNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		perror(output);
	else if (dup2(fd, OUT) == -1)
		perror("dup2 set up output");
	else
		return (SUCCESS);
	return (FAILURE);
}

int	setup_outputs(t_redir *output)
{
	while (output)
	{
		if (open_output(output->filename, output->type) == FAILURE)
			return (FAILURE);
		output = output->next;
	}
	return (SUCCESS);
}
