/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/21 15:46:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKEN_H
# define MINISHELL_TOKEN_H

/*
** NB_TOKEN : number of token types.
**			token types are defined in the enum e_token_type.
*/

# define NB_TOKEN	9

/*
** NB_METACHARACTER : 
*/

# define NB_METACHARACTER	6

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
** Struct token : for lexer.
**
**	type	: is the enum e_token_type
**	word	: is the string corresponding to type of token
**	len		: is the lenght of word 
			(for malloc easilly in parsing and get next token)
**	t_token	: prev and next to easily create t_cmd in parsing.
*/

typedef struct s_token	t_token;
struct s_token
{
	int		type;
	char	*word;
	size_t	len;
	t_token	*prev;
	t_token	*next;
};

/*
** token type for parsing.
**	'	"	|	<	>	<<	>>	$?	$VAR	{all rest = WORD}
*/

enum e_token_type
{
	SIMPLE_QUOTE,			//	'
	DOUBLE_QUOTE,			//	"
	PIPE,					//	|
	INPUT_REDIRECTION,		//	<
	OUTPUT_REDIRECTION,		//	>
	EXIT_STATUS,			//	$?
	VARIABLE,				// 	$VARIABLE
	WORD,					//  all not metacharacter
	HERE_DOC,				//	<<
	APPEND,					//	>>
};

/*
** enum for matching metacharacter and all functions defined in ft_get_token 
**	by the CHAR TYPE.
*/

enum e_ft_get_token
{
	FT_WORD,
	FT_SIMPLE_QUOTE,
	FT_DOUBLE_QUOTE,
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
t_token		*add_next_token(char *line, t_token *token_prev, t_func_get_token *get_token);

/*
** structures token and utils malloc and free
*/

t_token		*malloc_token(void);
void		free_this_token(t_token *token);
void		free_list_token(t_token **token);
void		remove_this_token(t_token *token);
t_token	*remove_multi_token(t_token **list_token, t_token *token, int nb);

/*
** usefull
*/

int			is_metacharacter(char c);
int			is_operator(char c);

char		*convert_double_quote(char *s); // A REFAIRE EXPANDER

#endif
