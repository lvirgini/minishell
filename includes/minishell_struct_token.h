/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct_token.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 16:34:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_TOKEN_H
# define MINISHELL_STRUCT_TOKEN_H

/*
** NB_TOKEN : number of token types.
**			token types are defined in the enum e_token_type.
*/

# define NB_TOKEN	9

/*
** Struct token : for lexer.
**
**	type	: is the enum e_token_type
**	word	: is the string corresponding to type of token
**	len		: is the lenght of word 
**			(for malloc easilly in parsing and get next token)
**	t_token	: prev and next to easily create t_cmd in parsing.
*/

typedef struct s_token	t_token;
struct s_token
{
	t_token	*next;
	t_token	*prev;
	char	*word;
	int		type;
	size_t	len;
};

/*
** token type
**	'	"	|	<	>	<<	>>	{all rest = WORD}
*/

enum e_token_type
{
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	WORD,
	HERE_DOC,
	APPEND,
};

/*
** structures token malloc - free - remove
*/

t_token		*malloc_token(void);
t_token		**malloc_list_token(void);
void		free_this_token(t_token *token);
void		free_list_token(t_token **token);
void		remove_this_token(t_token *token);
t_token		*remove_multi_token(t_token **list_token, t_token *token, int nb);

#endif
