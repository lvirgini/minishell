/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:52 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 19:02:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free all insider t_cmd and free it
*/

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->path)
		free(cmd->path);
	if (cmd->argv)
		free_list(cmd->argv);
	if (cmd->redir)
		free_list_redir(cmd->redir);
	if (cmd->heredoc)
		free_list_redir(cmd->heredoc);
	if (cmd->type == PIPE)
		close_pipe(cmd->pipe);
	free(cmd);
}

/*
** Free list of t_cmd
*/

void	free_list_cmd(t_cmd **cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd)
		return ;
	current = *cmd;
	while (current)
	{
		next = current->next;
		free_cmd(current);
		current = next;
	}
	free(cmd);
}
