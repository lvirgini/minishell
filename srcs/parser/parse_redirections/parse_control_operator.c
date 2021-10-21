/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_control_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:41:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 19:30:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	cmd_can_be_pipe(t_cmd *cmd)
{
	if (cmd->argv || cmd->input || cmd->output)
		return (true);
	return (false);
}
/*
** For Minishell only PIPE can be control operator.
** if | and nothing after : syntax error
** if nothing before | syntax error.
** else
*/

int	parse_control_operator(t_cmd *cmd, t_token **list_token)
{
	t_token		*token;

	token = *list_token;
	if (!token)
		return (SUCCESS);
	if (cmd_can_be_pipe(cmd) == false)
	{
		print_syntax_error(ERR_SYMBOL, 0, token->word);
		return (FAILURE);
	}
	if (!token->next)
	{
		print_syntax_error(ERR_SYMBOL, 0, NULL);
		return (FAILURE);
	}
	cmd->type = PIPE;
	remove_multi_token(list_token, token, 1);
	return (SUCCESS);
}
