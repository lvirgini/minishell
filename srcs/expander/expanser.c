/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/19 17:27:39 by eassouli         ###   ########.fr       */
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

char	**expand(char *str, char **env)
{
	if (str)
	{
		if (*str == CHAR_DOLLAR)
			return (expand_dollar(str, env));
	/*	else if (*str == CHAR_DOUBLE_QUOTE)
			return (expand_double_quote(str));
		else if (*str == CHAR_SIMPE_QUOTE)
			return (expand_simple_quote(str));*/
	}
	return (NULL);
}


int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd *cmd;

	if (!list_cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
		if (cmd->argv)
		{
			cmd->argv = expand_argv(cmd->argv, env);
			if (!cmd->argv)
				return (FAILURE);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
