/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:30:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 19:36:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir *add_t_redir(t_token *token)
{
	t_redir *redirection;

	redirection = (t_redir *)malloc(sizeof(t_redir));
	if (!redirection)
	{
		perror("malloc add_t_redir()");
		return (NULL);
	}
	redirection->next = NULL;
	redirection->filename = ft_strdup(token->word);
	return (redirection);
}

void	add_back_t_redir(t_redir *redirection, t_redir *to_add)
{
	while (redirection->next)
		redirection = redirection->next;
	//redirection->next = add_t_redir(token);
	redirection->next = to_add;
}

t_cmd	*create_cmd(t_cmd *prev, t_token **token)
{
	t_cmd	*cmd;

	cmd = malloc_cmd(prev);
	if (!cmd)
		return (NULL);
	if (parse_all_redirection(cmd, token) == FAILURE
	|| parse_cmd_argv(cmd, token) == FAILURE
	|| parse_control_operator(cmd, token) == FAILURE)
	{
		free_cmd(cmd);
		return (NULL);
	}
	return (cmd);
}
/*
static void	set_functions_parse_token(t_ft_parser ft_token[NB_TOKEN])
{
//	ft_token[FT_SIMPLE_QUOTE] = &parse_simple_quote;
//	ft_token[FT_DOUBLE_QUOTE] = &parse_double_quote;
//	ft_token[FT_PIPE] = &parse_pipe;
//	ft_token[FT_TILD_LEFT] = &parse_;
//	ft_token[FT_TILD_RIGHT] = &parse_tild_right;
//	ft_token[FT_DOLLAR] = &parse_special_param;
//	ft_token[FT_WORD] = &parse_token_word;
}
*/

// PEUT ETRE FUSIONNER GET NEXT CMD ET CREATE CMD ...

t_cmd *get_next_cmd(t_cmd *prev, t_token **token)
{
	t_cmd *cmd;
//	static t_ft_parser	ft_parser[NB_TOKEN];

//	set_functions_parse_token(ft_parser);
	if (!token || !*token) // a check ?
		return (NULL);
	cmd = create_cmd(prev, token);

	return (cmd);
}
