/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 16:43:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
t_bool	need_expand(char *str)
{
	static char *expand_char = "\"\'$";

	if (ft_strchr_len(expand_char, str[0]))
		return (true);
	return (false);
}

char	*expand(char *str)
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

int	expand_argv(char **argv)
{
	int		i;
	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			if (need_expand(argv[i]) == true)
			{
				
			}
			argv[i] = expand(argv[i]);
			if (!argv[i])
				return (FAILURE);	//
			i++;
		}
	}
	return (SUCCESS);
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

int	expanser(t_cmd **list_cmd, char **env)
{
	t_cmd *cmd;

	if (!cmd)
		return (FAILURE);
	cmd = *list_cmd;
	while (cmd)
	{
		if (!expand_redirection(cmd->input)
			|| !expand_redirection(cmd->output)
			|| !expand_argv(cmd->argv))
			return(FAILURE);
		cmd = cmd->next;
	}
	return (SUCCESS);
}*/