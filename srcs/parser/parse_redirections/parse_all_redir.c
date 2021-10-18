/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:32:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 16:34:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if syntax for input is correct
**	parse input
*/

t_redir		*parse_redir(t_token *token)
{
	t_redir *redir;

	if (!token->next)
		return (FAILURE);	// SYNTAX ERROR ( > et rien derriere)
//	if (is_token_filename(token->next) == false)
		return (FAILURE);	// SYNTAX ERROR ( > et rien derriere)
//	redir = add_t_redir(token->type, token->next);
//	remove_multi_token(token, 2);
	return (redir);
}

int	parse_all_redirection(t_cmd *cmd, t_token **all_token)
{
	t_token	*token;
	int		syntax;

	token = *all_token;
	while (token && is_token_control_operator(token->type) == false)
	{
		syntax = 0;
/*		if (token->type == INPUT_REDIRECTION)
			syntax = parse_input(cmd, token);
		else if (token->type == OUTPUT_REDIRECTION)
			syntax = parse_output(cmd, token);
		else if (token->type == HERE_DOC)
			syntax = parse_here_doc(cmd, token);
		else if (token->type == APPEND)
			syntax = parse_append(cmd, token);
		else
			token = token->next;*/
////		if (syntax = SYNTAX_ERROR)
///			return (SYNTAX_ERROR); /// ERROR a mettre en place 
	}
	return (syntax);
	/*	{
			if (!token->next)
				return (FAILURE);
			if (token->next != WORD) // SYNTAX ERROR ( > et rien derriere)
			if (!cmd->input)
				cmd->input = add_t_redir(token->next);

		}	*/
}