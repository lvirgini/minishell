/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:38:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 16:51:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if syntax for input is correct
**	parse input to t_redir *
**	place in cmd.
*/

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
