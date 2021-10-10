/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 14:43:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKEN_H
# define MINISHELL_TOKEN_H

# define NB_TOKEN	9
# define NB_METACHARACTER	6

//// META_  ou CHAR_  ???
# define META_SIMPE_QUOTE 	'\''
# define META_DOUBLE_QUOTE 	'\"'
# define META_PIPE			'|'
# define META_TILD_LEFT		'<'
# define META_TILD_RIGHT	'>'
# define META_DOLLAR		'$'
/* UNUSED FOR MINISHELL
# define META_AND			'&'
# define META_SEMICOLON		';'
# define META_PARENTH_LEFT	'('
# define META PARENTH_RIGHT	')'
*/

/*
** enum for matching metacharacter and ft_get_token by type.
*/

enum e_ft_get_token
{
	FT_WORD,
	FT_SIMPLE_QUOTE,
	FT_DOUBLE_QUOTE,
	FT_PIPE,
	FT_TILD_LEFT,
	FT_TILD_RIGHT,
	FT_DOLLAR,
};

/*
** token type for parsing.
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
** Struct token : for lexer.
**
**	type is enum of metacharacters or redirections
**	word is the string corresponding to type of token
**	len is the lenght of word (for malloc easilly in parsing and get next token)
**	token prev and next for easy way to create t_cmd in parsing.
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
** for getting good token
*/

typedef	int	(*t_func)(t_token *, char *);

int			get_token_word(t_token *token, char *line);
int			get_token_simple_quote(t_token *token, char *line);
int			get_token_double_quote(t_token *token, char *line);
int			get_token_special_param(t_token *token, char *line);
int			get_token_pipe(t_token *token, char *line);
int			get_token_tild_left(t_token *token, char *line);
int			get_token_tild_right(t_token *token, char *line);

/*
** Lexer functions
*/

t_token		*add_next_token(char *line, t_token *token_prev, t_func *get_token);

/*
** structures token and utils malloc and free
*/

t_token		*malloc_token(void);
void		free_this_token(t_token *token);
void		free_all_token(t_token **token);
void		remove_this_token(t_token *token);

/*
** usefull
*/

int			is_metacharacter(char c);




/* CHECK error synthax

DOUBLE QUOTE = %2
SIMPLE_QUOTE = %2
redirections need WORD after
:

HEREDOC
OUVRE LES INPUT/OUTPUT  (ecrase le heredock ou les pipes)
ESSAIE DE TROUVERLA COMMANDE

<< tata cat < Makefile 
> dfg
> dfg
> dfg
> dfg
> dfg
> tata
# **************************************************************************** #
#                                                                              #
(...)

 << cat -e | iii < sdfsdfsdfsdf
> cat
bash: sdfsdfsdfsdf: Aucun fichier ou dossier de ce type
bash: -e : commande introuvable


< cat -e | sdfsdfsdfsdf
bash: sdfsdfsdfsdf : commande introuvable
bash: cat: Aucun fichier ou dossier de ce type

< cat -e
bash: cat: Aucun fichier ou dossier de ce type

cat -e >
bash: erreur de syntaxe près du symbole inattendu « newline »

cat -e >> | echo hello
bash: erreur de syntaxe près du symbole inattendu « | »

HEREDOC need WORD DELIMITER after
<< cat -e
> cat -e
> cat
bash: -e : commande introuvable

SPECIALPARAMETER need ?(=last exit status) or WORD after (= variable)
 if WORD is no others needed cité au dessus, its a command
 all WORD after command is arguments.

struct cmd_status
{
	double_quote = nb
	simple_quote = nb
	pipe_with_nothing_after / before =
	redirection_with_no_word_after = 


}*/

/* ALL : NOT REQUIRED FOR MINISHELL
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
*/

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

get_next token(**token)
NEED: 	
		new token = malloc
		len = 0
		token type = getmetacharacter(line);
		token value = get_token value(line, &len)
		line += len;
		if (*token == NULL)
			*token = new_token;
		else
			token->next = new_token;
		return (len);


t_token **create_lexer_token_minishell(char *line)
{
	token = malloc **token;

	len = get_next_token(token, line)
	line += token->len
	while (*line)
	{
		if (lineisspace)
			line++;
		else
			token->next = get_next_token(line)
			line += token->len
			token = token next;
	}
}


CMD PARSER



parsing

token **t;

while *t
{
	cmd = get_next_cmd(token, &cmd_status)
}

*/


#endif