/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:54:51 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/18 16:04:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LEXER_H
# define MINISHELL_LEXER_H

# include "minishell.h"

/*
** NB_METACHARACTER : 
*/

# define NB_METACHARACTER	4

/*
** Define used for the lexer :
** for all split, if one of this char is found, stop the token.
*/

# define CHAR_SIMPE_QUOTE 	'\''
# define CHAR_DOUBLE_QUOTE 	'\"'
# define CHAR_PIPE			'|'
# define CHAR_TILD_LEFT		'<'
# define CHAR_TILD_RIGHT	'>'
# define CHAR_DOLLAR		'$'

/*
** enum for matching metacharacter and all functions defined in ft_get_token 
**	by the CHAR TYPE.
*/

enum e_ft_get_token
{
	FT_WORD,
	FT_PIPE,
	FT_TILD_LEFT,
	FT_TILD_RIGHT,
};

/*
** function get_token
**
** with enum ft_get_token.
** correctly retrieve each token according to its type
*/

typedef int	(*t_func_get_token)(t_token *, char *);

int			get_token_word(t_token *token, char *line);
int			get_token_simple_quote(t_token *token, char *line);
int			get_token_double_quote(t_token *token, char *line);
int			get_token_pipe(t_token *token, char *line);
int			get_token_tild_left(t_token *token, char *line);
int			get_token_tild_right(t_token *token, char *line);

/*
** Lexer functions
*/

t_token		**lexer_minishell(char *line);
t_token		*add_next_token(char *line, t_func_get_token *get_token);

/*
** usefull
*/

int			is_metacharacter(char c);
int			is_operator(char c);
char		*convert_double_quote(char *s); // A REFAIRE EXPANDER

#endif
