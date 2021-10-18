/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:30:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/18 19:54:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 	check if token type is a control operator ( for separate cmd)
**
**	static int	control_operator[NB_OPERATOR] = {PIPE, AND, ...}
**	in minishell only PIPE is used.
*/

int	is_token_control_operator(int token_type)
{
	if (token_type == PIPE)
		return (true);
	return (false);
}

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

t_cmd	create_cmd(t_token **token)
{
	t_cmd cmd;

	parse_all_redirection(&cmd, token);
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
t_cmd *get_next_cmd(t_cmd *prev, t_token **token)
{
	t_cmd		*cmd;
//	static t_ft_parser	ft_parser[NB_TOKEN];

//	set_functions_parse_token(ft_parser);
	if (!token && !*token) // a check ?
		return (NULL);
	cmd = malloc_t_cmd(prev);
	if (!cmd)
		return (NULL);
	while (*token && is_token_control_operator((*token)->type) == false)
	{
		*cmd = create_cmd(token);

	}
}