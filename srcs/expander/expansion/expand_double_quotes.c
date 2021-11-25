/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:51:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/22 22:30:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	The backslash retains its special meaning only when followed by one of the 
**	following characters: ‘$’, ‘`’, ‘"’, ‘\’, or newline
**	"$USER$$$$$\\\`\"""""""""""""$USER$OK""""   "
*/

static size_t	strlen_without_double_quotes(char *s, size_t s_len,
		t_expansion *sub_expansion)
{
	static char	*escape_quotes = STR_ESCAPE_IN_DQUOTES;
	size_t		len;
	size_t		i;

	len = 0;
	i = 1;
	while (s[i] && i + 1 < s_len)
	{
		if (sub_expansion && sub_expansion->value
			&& i == sub_expansion->start_of_the_expand)
		{
			i += sub_expansion->size_to_remove;
			len += ft_strlen(sub_expansion->value[0]);
			sub_expansion++;
		}
		else
		{
			if (s[i] == BACKSLASH && ft_strchr(escape_quotes, s[i + 1]))
				i++;
			len++;
			i++;
		}
	}
	return (len);
}

/*
**
**	static char	escape_quotes[] = {CHAR_DOLLAR, CHAR_DOUBLE_QUOTE, BACKSLASH,
**					GRAVE_ACCENT, '\0'};
*/

size_t	strcpy_sub_expansion_double_quotes(char *result,
		t_expansion *sub_expansion)
{
	if (sub_expansion->value && sub_expansion->value[0])
	{
		ft_strcpy(result, sub_expansion->value[0]);
		return (ft_strlen(sub_expansion->value[0]));
	}	
	return (0);
}

static void	strcpy_double_quotes_expand(char *result,
		t_expansion *sub_expansion, char *s, size_t max_len)
{
	static char	*escape_quotes = STR_ESCAPE_IN_DQUOTES;
	size_t		len_expand;
	size_t		i;

	i = 1;
	len_expand = 0;
	while (s[i] && i + 1 < max_len)
	{
		if (sub_expansion && i == sub_expansion->start_of_the_expand)
		{
			len_expand = strcpy_sub_expansion_double_quotes(
					result + len_expand, sub_expansion);
			i += sub_expansion->size_to_remove;
			sub_expansion = sub_expansion->next;
		}
		else
		{
			if (s[i] == BACKSLASH && ft_strchr(escape_quotes, s[i + 1]))
				i++;
			result[len_expand++] = s[i++];
		}
	}
	result[len_expand] = '\0';
}

static t_expansion	*removed_and_expand_double_quotes(char *s,
		t_expansion *sub_expansion, size_t max_len)
{
	t_expansion	*expansion;

	expansion = malloc_expansion_and_value(1);
	if (!expansion)
		return (NULL);
	expansion->size_to_remove = max_len;
	expansion->value[0] = (char *)malloc(sizeof(char)
			* (1 + strlen_without_double_quotes(s, max_len, sub_expansion)));
	if (!expansion->value[0])
	{
		free_list_expansion(expansion);
		return (NULL);
	}
	strcpy_double_quotes_expand(expansion->value[0], sub_expansion, s, max_len);
	return (expansion);
}

/*
**	expand double quotes :
**
**	get strlen des doubles quotes a retirer (l'ensemble)
**	get les dollars sub_expansions si il y en a
**	expandre la chaine finale a mettre dans expansion
**	get strlen final sans les \escapes et la size to remove
**		de toutes les expansion dollar
**
*/

t_expansion	*expand_double_quote(char *s, char **env)
{
	size_t		size_to_remove;
	t_expansion	*expansion;
	t_expansion	*sub_expansion;

	printf("expand double quotes : %s\n", s);
	size_to_remove = strlen_double_quote(s, 0);
	sub_expansion = NULL;
	if (ft_strnchr(s, CHAR_DOLLAR, size_to_remove))
	{
		sub_expansion = expand_dollar_in_double_quotes(s, env, size_to_remove);
		if (!sub_expansion)
			return (NULL);
	}
	expansion = removed_and_expand_double_quotes(s, sub_expansion,
			size_to_remove);
	if (!expansion)
	{
		perror("malloc expand_simple_quotes()");
		free_list_expansion(sub_expansion);
		return (NULL);
	}
	free_list_expansion(sub_expansion);
	return (expansion);
}
