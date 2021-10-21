/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:32:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 17:38:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** SYNTAX ERROR from redirections : 
**
** if no token after redirection : it's the end of line
** if token after is another redirection or operator
*/

int	syntax_error_redirection(t_token *token)
{
	if (!token->next)
	{
		print_syntax_error(ERR_SYMBOL, '\0', NULL);
		return (SYNTAX_ERROR);
	}
	if (is_token_words(token->next->type) == false)
	{
		print_syntax_error(ERR_SYMBOL, 0, token->next->word);
		return (SYNTAX_ERROR);
	}
	return (SUCCESS);
}

int	parse_all_redirection(t_cmd *cmd, t_token **list_token)
{
	t_token	*token;
	int		syntax;

	token = *list_token;
	while (token && is_token_control_operator(token->type) == false)
	{
		syntax = SUCCESS;
		if (token->type == INPUT_REDIRECTION || token->type == HERE_DOC)
		{
			syntax = parse_input(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}	
		else if (token->type == OUTPUT_REDIRECTION || token->type == APPEND)
		{
			syntax = parse_output(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}
		else
			token = token->next;
		if (syntax != SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}
