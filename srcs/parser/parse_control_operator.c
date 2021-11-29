/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_control_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:41:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 21:36:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	cmd_can_be_pipe(t_cmd *cmd)
{
	if (cmd->argv || cmd->redir || cmd->heredoc)
		return (true);
	return (false);
}
/*
** For Minishell only PIPE and newline can be control operator.
** if no token exist : it's newline.
** if PIPE and nothing after : syntax error
** if nothing before PIPE (cmd is empty) syntax error.
*/

int	parse_control_operator(t_cmd *cmd, t_token **list_token)
{
	t_token		*token;

	token = *list_token;
	if (!token)
		return (SUCCESS);
	if (cmd_can_be_pipe(cmd) == false)
	{
		display_syntax_error(ERR_SYMBOL, 0, token->word);
		return (FAILURE);
	}
	if (!token->next)
	{
		display_syntax_error(ERR_SYMBOL, 0, NULL);
		return (FAILURE);
	}
	cmd->type = PIPE;
	remove_multi_token(list_token, token, 1);
	return (SUCCESS);
}
