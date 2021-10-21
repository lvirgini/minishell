/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:18:56 by mini              #+#    #+#             */
/*   Updated: 2021/10/21 15:46:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** a special fonction for malloc t_token ** and his first element
*/

static t_token	**malloc_first_token(char *line, t_func_get_token *get_token)
{
	t_token		**token;

	token = (t_token **)malloc(sizeof(t_token *)); //
	if (!token)
		return (NULL);
	*token = add_next_token(line, NULL, get_token);
	if (!*token)
	{
		free_list_token(token);
		return (NULL);
	}
	return (token);
}

/*
**	implementation of the functions get_token()
**	which allow to recover correctly each token according to its type
*/

static void	set_functions_get_token(t_func_get_token ft_token[NB_METACHARACTER])
{
	ft_token[FT_SIMPLE_QUOTE] = &get_token_simple_quote;
	ft_token[FT_DOUBLE_QUOTE] = &get_token_double_quote;
	ft_token[FT_PIPE] = &get_token_pipe;
	ft_token[FT_TILD_LEFT] = &get_token_tild_left;
	ft_token[FT_TILD_RIGHT] = &get_token_tild_right;
	ft_token[FT_WORD] = &get_token_word;
}

/*
** pass the spaces in the line and return the ptr.
*/

static char	*pass_spaces_in_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (line);
}

static char	*move_line_for_next_token(char *line, t_token *current)
{
	if (current)
		line += current->len;
	return (pass_spaces_in_line(line));
}

/*
** Global lexer :
**		walk the line while it exists
**		pass all spaces
**		send to function add_next_token() to retrieve the following token.
**		shifts the line by the length of the recovered token
*/

t_token	**lexer_minishell(char *line)
{
	t_token					**token;
	t_token					*current;
	static t_func_get_token	get_token[NB_METACHARACTER];

	set_functions_get_token(get_token);
	line = pass_spaces_in_line(line);
	token = malloc_first_token(line, get_token);
	if (!token)
		return (NULL);
	current = *token;
	line = move_line_for_next_token(line, current);
	while (*line)
	{
		current->next = add_next_token(line, current, get_token);
		current = current->next;
		if (!current && *line)
		{
			free_list_token(token);
			return (NULL);
		}
		line = move_line_for_next_token(line, current);
	}
	return (token);
}
