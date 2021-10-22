/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:00:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 13:32:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_H
# define MINISHELL_PARSER_H

# include "minishell.h"

/*
** general rules for parsing
*/

t_cmd		**parser_minishell(t_token **token);
t_cmd		*get_next_cmd(t_token **token);

/*
** parse all different token
*/

int			parse_all_redirection(t_cmd *cmd, t_token **all_token);
int			parse_input(t_cmd *cmd, t_token *token);
int			parse_output(t_cmd *cmd, t_token *token);
int			parse_cmd_argv(t_cmd *cmd, t_token **list_token);
int			parse_control_operator(t_cmd *cmd, t_token **list_token);

/*
**	utils
*/

t_bool		is_token_control_operator(int token_type);
t_bool		is_token_words(int token_type);
int			syntax_error_redirection(t_token *token);

#endif
