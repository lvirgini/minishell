/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hdoc_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:05:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/28 00:03:37 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_simple_quotes(char *res, char *s, size_t *s_len,
		size_t *res_len)
{
	(*s_len)++;
	while (s[*s_len] != CHAR_SIMPLE_QUOTE)
		res[(*res_len)++] = s[(*s_len)++];
	(*s_len)++;
}

static void	remove_double_quotes(char *res, char *s, size_t *s_len,
		size_t *res_len)
{
	static char	*escape_quotes = STR_ESCAPE_IN_DQUOTES;

	(*s_len)++;
	while (s[*s_len] != CHAR_DOUBLE_QUOTE)
	{
		if (s[*s_len] == BACKSLASH && ft_strchr(escape_quotes, s[*s_len + 1]))
				(*s_len)++;
		res[(*res_len)++] = s[(*s_len)++];
	}
	(*s_len)++;
}

static char	*removed_quotes(char *s)
{
	char	*result;
	size_t	s_len;
	size_t	res_len;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	s_len = 0;
	res_len = 0;
	while (s[s_len])
	{
		if (s[s_len] == CHAR_SIMPLE_QUOTE)
		{
			remove_simple_quotes(result, s, &s_len, &res_len);
		}
		else if (s[s_len] == CHAR_DOUBLE_QUOTE)
		{
			remove_double_quotes(result, s, &s_len, &res_len);
		}
		else
			result[res_len++] = s[s_len++];
	}
	result[res_len] = '\0';
	return (result);
}

static t_bool	need_expand_delimitor(char *delimitor)
{
	if (ft_strchr_set(delimitor, "\'\""))
		return (true);
	return (false);
}

t_hdoc	*create_heredoc(char *delimitor)
{
	t_hdoc	*heredoc;

	heredoc = malloc_heredoc();
	if (need_expand_delimitor(delimitor))
		heredoc->delimitor = removed_quotes(delimitor);
	else
	{
		heredoc->need_expand = true;
		heredoc->delimitor = ft_strdup(delimitor);
	}
	if (!delimitor)
	{
		perror("malloc in create_heredoc()");
		return (NULL);
	}
	return (heredoc);
}
