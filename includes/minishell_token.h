/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/08 13:55:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKEN_H
# define MINISHELL_TOKEN_H

typedef struct s_token	t_token;
struct s_token
{
	int		type;
	char	*word;
	t_token	*next;
};

enum e_token_type
{
	WORD,					// not special type
	STRING,					// inside quotes
	SEQUENCE,				//	;
	GROUP_LEFT,				//	(
	GROUP_RIGHT,			//	)
	PIPE,					//	|
	OR,						// 	||
	BACKGROUND,				//	&
	AND, 					//	&&
	INPUT_REDIRECTION,		//	<
	OUTPUT_REDIRECTION,		//	>
	HERE_DOC,				//	<<
	APPEND,					//	>>
	SIMPE_QUOTE,			//	'
	DOUBLE_QUOTE,			//	"
	SPECIAL_PARAMETER,		//	$
};

/*
t_token	*lexer_line(char *line)
{
	split_line = split_minishell_line()
	if (line)
		return NULL;
	t_token all_token = malloc token();
	if (!token)
		return NULL;
	token = get_all_token(split_line);
	free_double_tab(line);
	if (!token)
		return NULL
	return token;
}

split_minishell(char *line)
{
	while (*line)
	{
		len = get_next_token(token, line)
		token = token next;
		line += len
	}
}
*/


#endif