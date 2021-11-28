/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:10:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/28 15:30:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Special expansion for HEREDOC line.
*/

static t_expansion	*expand_only_dollar(char *s, char **env)
{
	size_t		i;
	t_expansion	*expansion;
	t_expansion	*first;

	i = 0;
	first = NULL;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR)
		{
			expansion = expand_dollar(s + i, env, false);
			if (!expansion)
			{
				free_list_expansion(first);
				return (NULL);
			}
			expansion->start_of_the_expand = i;
			i += expansion->size_to_remove;
			first = add_back_expansion(first, expansion);
		}
		else
			i++;
	}
	return (first);
}

static t_bool	is_dollar_expansion(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR)
			return (true);
		i++;
	}
	return (false);
}

/*
** expand line receive by STDIN for heredoc.
*/

char	*expand_heredoc_line(char *line, char **env)
{
	t_expansion	*expansion;
	char		*result;

	if (is_dollar_expansion(line))
	{
		expansion = expand_only_dollar(line, env);
		if (!expansion)
			return (FAILURE);
		result = fusion_str_expansion(line, expansion);
		free_list_expansion(expansion);
		free(line);
		return (result);
	}
	return (line);
}
