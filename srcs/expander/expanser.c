/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 16:34:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

SI "" puis dollar : prend aussi les espace
{
	dqutes dollar = literal value
	// Unquoted implicit null arguments, resulting from the expansion of
	 parameters that have no values, are removed.
}

SI dollar : escape space
MAIS SI il y a des chaine null "" ou '' elles sont supprimée 

mini@debian:~$ export TEST=-d''""test
mini@debian:~$ echo $TEST 
-dtest
*/

int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;

	if (!list_cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
		if (cmd->argv)
		{
			expand_argv(cmd, env);
			if (!cmd->argv)
				return (FAILURE);
			print_cmd(cmd);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}

/* OLD
int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd	*cmd;
	char 	**new_argv;

	if (!list_cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
		if (cmd->argv)
		{
			new_argv = expand_argv(cmd->argv, env);
			cmd->argv = new_argv;
			if (!cmd->argv)
				return (FAILURE);
			print_cmd(cmd);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
*/