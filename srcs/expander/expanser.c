/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/05 08:09:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
t_expansion	*expand(char *str)
{
	if (str)
	{
		if (str[0] == CHAR_DOUBLE_QUOTE)
			return (expand_double_quote(str));
		if (str[0] == CHAR_SIMPE_QUOTE)
			return (expand_simple_quote(str));
		if (str[0] == CHAR_DOLLAR)
			return (expand_dollar(str));
	}
	return (str);
}

int	expand_redirection(t_redir *redir)
{
	while (redir)
	{
		if (!expand(redir->filename))
			return (FAILURE);
		redir = redir->next;
	}
	return (SUCCESS);
}

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
		if (need_expand_argv(cmd->argv) == true)
		{
			cmd->argv = expand_argv(cmd->argv, env);
			if (!cmd->argv)
				return (FAILURE);
		}
	/*	if (need_expand_redirection(cmd->input))
		{
			cmd->input = expand_redirection(cmd->input);
			if (!cmd->input)
				return (FAILURE);
		}
		if (need_expand_redirection(cmd->output))
		{
			cmd->input = expand_redirection(cmd->input);
			if (!cmd->input)
				return (FAILURE);
		}*/
		cmd = cmd->next;
	}
	return (SUCCESS);
}
