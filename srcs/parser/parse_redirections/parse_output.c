/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:42:46 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:59:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if syntax for output is correct
**	parse output to t_redir *
**	place in cmd.
*/

int	parse_output(t_cmd *cmd, t_token *token)
{
	t_redir	*output;

	if (syntax_error_redirection(token) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	output = add_redir(token);
	if (!output)
		return (FAILURE);
	if (!cmd->output)
		cmd->output = output;
	else
		add_back_redir(cmd->output, output);
	return (SUCCESS);
}
