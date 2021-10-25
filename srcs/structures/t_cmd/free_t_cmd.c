/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:52 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 19:28:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list_char(char **list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

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
		free_list_char(cmd->argv);
	if (cmd->input)
		free_list_redir(cmd->input);
	if (cmd->output)
		free_list_redir(cmd->output);
	free(cmd);
}

/*
** Free list of t_cmd
*/

void	free_list_cmd(t_cmd **cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd || !*cmd)
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
