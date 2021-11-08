/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:33:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/08 17:16:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_std_io(int std_io[2])
{
	std_io[IN] = dup(IN);
	std_io[OUT] = dup(OUT);
}

void	get_back_std_io(int std_io[2])
{
	close(IN);
	close(OUT);
	dup2(std_io[IN], IN);// protection
	dup2(std_io[OUT], OUT);//
}

int		setup_redirections(t_cmd *cmd)
{
	t_redir	*input;
	t_redir	*output;

	if (make_pipe_redirection(cmd) == FAILURE)
		return (FAILURE);
	// MAKE HERE DOC here
	input = cmd->input;
	while (input)
	{
		if (set_up_input(input->filename) == FAILURE)
			return (FAILURE);
		input = input->next;
	}
	// if HEREDOC is last : here doc = input
	// else close HEREDOC ?
	output = cmd->output;
	while (output)
	{
		if (set_up_output(cmd, output->filename) == FAILURE)
			return (FAILURE);
		output = output->next;
	}
	return (SUCCESS);
}