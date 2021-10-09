/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mini <mini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:18:56 by mini              #+#    #+#             */
/*   Updated: 2021/10/09 20:33:14 by mini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** a special fonction for malloc t_token ** and his first element
*/

t_token	**malloc_first_token(line)
{
	t_token		**token;

	token = (t_token **)malloc(sizeof(t_token **));
	if (!token)
		return (NULL);
	*token = get_next_token(line, NULL);
	if (*token)
	{
		free_all_token(token);
		return (NULL);
	}
	return (token);
}


static void		set_fonction_get_token(t_func ft_token[NB_TOKEN])
{
	ft_token[WORD] = &get_token_word;
	ft_token[SIMPLE_QUOTE] = &get_token_simple_quote;
	ft_token[DOUBLE_QUOTE] = &get_token_double_quote;
	ft_token[SPECIAL_PARAMETER] = &get_token_special_param;
	ft_token[PIPE] = &get_token_metacharacter;
	ft_token[INPUT_REDIRECTION] = &get_token_metacharacter;
	ft_token[OUTPUT_REDIRECTION] = &get_token_metacharacter;
	ft_token[HERE_DOC] = &get_token_metacharacter;
	ft_token[APPEND] = &get_token_metacharacter;
}

/*
** get next token from line
*/

t_token	*get_next_token(char *line, t_token *token_prev, t_func get_token[NB_TOKEN])
{
	t_token			*token;
	int				syntax_error;

	get_token = get_fonction_token();
	token = malloc_token();
	if (!token)
		return (NULL);
	while (*line)
	{
		token->type = get_token_type(line);
		syntax_error = get_token[token->type](token, line);
	}
	token	
}

/*
** Global lexer : parcours line tant qu'elle existe
**		passe les espaces
**		recupere le prochain token
**		avance line en fonction de la longueur recuperer par le token
*/

t_token	**lexer_minishell(char *line)
{
	t_token		**token;
	t_token		*current;
	t_func		get_token[NB_TOKEN];

	set_functions_get_token();
	token = malloc_first_token(line, get_token);
	if (!token)
		return (NULL);
	current = *token;
	line += current->len;
	while (*line)
	{
		if (ft_isspace(*line))
			line++;
		else
		{
			current->next = get_next_token(line, current, get_token);
			current = current->next;
			if (!current)
			{
				free_all_token(token);
				return (NULL);
			}
			line += current->len;
		}
	}
	return (token);
}
