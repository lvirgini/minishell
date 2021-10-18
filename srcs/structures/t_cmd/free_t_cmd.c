/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:52 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 16:35:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free all insider t_cmd and free it
*/

void	free_t_cmd(t_cmd *cmd)
{
/*	if (!cmd)
		return ;
	if (cmd->path)
		free(cmd->path);
	if (cmd->argv)
		free_double_tab(cmd->argv);
	if (cmd->input)
		free_t_redir(cmd->input);
	if (cmd->output)
		free_t_redir(cmd->output);*/
	free(cmd);
}

/*
** Free list of t_cmd
*/

void	free_list_t_cmd(t_cmd **cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd)
		return ;
	current = *cmd; 
	while (current)
	{
		next = current->next;
		free_t_cmd(current);
		current = next;
	}
	free(cmd);
}
