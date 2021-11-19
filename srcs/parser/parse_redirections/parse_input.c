/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:38:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/18 16:07:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if syntax for input is correct
**	parse input to t_redir *
**	place in cmd.
*/
/*
int	parse_redirection(t_cmd *cmd, t_token *token)
{
	t_redir	*redir;

	if (syntax_error_redirection(token) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	redir = create_redir(token->type, token->next->word);
	if (!redir)
		return (FAILURE);
	if (redir->type == HERE_DOC)
	{
		if (!cmd->heredoc)
			cmd->heredoc = redir;
		else
			struct_add_back(cmd->heredoc, redir);
	}
	else
	{
		if (!cmd->redir)
			cmd->redir = redir;
		else
			struct_add_back(cmd->redir, redir);
	}
	return (SUCCESS);
}*/

/*
int	parse_input(t_cmd *cmd, t_token *token)
{
	t_redir	*input;

	if (syntax_error_redirection(token) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	input = create_redir(token->type, token->next->word);
	if (!input)
		return (FAILURE);
	if (!cmd->input)
		cmd->input = input;
	else
		struct_add_back(cmd->input, input);
	return (SUCCESS);
}
*/