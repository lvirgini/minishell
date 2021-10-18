/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:38:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 21:53:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if syntax for input is correct
**	parse input
*/

int	parse_input(t_cmd *cmd, t_token *token)
{
	if (!cmd->input)
		cmd->input = parse_redir(token);
	else
		add_back_t_redir(cmd->input, parse_redir(token));
	return (1); ////
}


test_builtin_echo()
{
	t_cmd;

	cmd->path = "/bin/echo";
}