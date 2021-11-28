/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:18:56 by mini              #+#    #+#             */
/*   Updated: 2021/11/27 22:18:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	implementation of the functions get_token()
**	which allow to recover correctly each token according to its type
*/

static void	set_functions_get_token(t_func_get_token ft_token[NB_METACHARACTER])
{
	ft_token[FT_WORD] = &get_token_word;
	ft_token[FT_PIPE] = &get_token_pipe;
	ft_token[FT_TILD_LEFT] = &get_token_tild_left;
	ft_token[FT_TILD_RIGHT] = &get_token_tild_right;
}

static char	*move_line_for_next_token(char *line, t_token *current)
{
	if (current)
		line += current->len;
	return (pass_str_spaces(line));
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
	t_token				**list_token;
	t_token				*new_token;
	t_func_get_token	get_token[NB_METACHARACTER];

	set_functions_get_token(get_token);
	list_token = malloc_list_token();
	if (!list_token)
		return (NULL);
	line = pass_str_spaces(line);
	while (*line)
	{
		new_token = add_next_token(line, get_token);
		if (!new_token && *line)
		{
			free_list_token(list_token);
			return (NULL);
		}
		struct_list_add_back(list_token, new_token);
		line = move_line_for_next_token(line, new_token);
	}
	return (list_token);
}
