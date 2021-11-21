/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:33:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 20:37:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_std_io(int std_io[2])
{
	std_io[IN] = dup(IN);
	std_io[OUT] = dup(OUT);
}

int	get_back_std_io(int std_io[2])
{
	close(IN);
	close(OUT);
	if (dup2(std_io[IN], IN) == -1)
	{
		perror ("dup2() in get_back_std_io()");
		return (FAILURE);
	}
	if (dup2(std_io[OUT], OUT) == -1)
	{
		perror ("dup2() in get_back_std_io()");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	setup_all_redirections(t_cmd *cmd, char **env)
{
	if (make_pipe_redirection(cmd) == FAILURE)
		return (FAILURE);
	// MAKE HERE DOC here
	if (setup_redirection(cmd, env) == FAILURE)
		return (FAILURE);
	// if HEREDOC is last : here doc = input
	// else close HEREDOC ?
	return (SUCCESS);
}
