/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:18:56 by mini              #+#    #+#             */
/*   Updated: 2021/10/15 13:20:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** a special fonction for malloc t_token ** and his first element
*/

t_token	**malloc_first_token(char *line, t_func *get_token)
{
	t_token		**token;

	token = (t_token **)malloc(sizeof(t_token **));
	if (!token)
		return (NULL);
	*token = add_next_token(line, NULL, get_token);
	if (!*token)
	{
		free_all_token(token);
		return (NULL);
	}
	return (token);
}

//a mettre en bon anglais:
/*
** set up functions for get in the good way all token by their type.
*/

static void	set_functions_get_token(t_func ft_token[NB_TOKEN])
{
	ft_token[FT_SIMPLE_QUOTE] = &get_token_simple_quote;
	ft_token[FT_DOUBLE_QUOTE] = &get_token_double_quote;
	ft_token[FT_PIPE] = &get_token_pipe;
	ft_token[FT_TILD_LEFT] = &get_token_tild_left;
	ft_token[FT_TILD_RIGHT] = &get_token_tild_right;
	ft_token[FT_DOLLAR] = &get_token_special_param;
	ft_token[FT_WORD] = &get_token_word;
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
	t_func		get_token[NB_METACHARACTER];

	set_functions_get_token(get_token);
	token = malloc_first_token(line, get_token);
	if (!token)
		return (NULL);
	current = *token;
	line += current->len;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		current->next = add_next_token(line, current, get_token);
		current = current->next;
		if (!current && *line)
		{
			free_all_token(token);
			return (NULL);
		}
		line += current->len;
	}
	return (token);
}
