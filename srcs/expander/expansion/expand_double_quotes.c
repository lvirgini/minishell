/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:51:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 23:07:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	The backslash retains its special meaning only when followed by one of the 
**	following characters: ‘$’, ‘`’, ‘"’, ‘\’, or newline
*/

char	*removed_and_expand_double_quotes(char *s, int	quotes_len)
{
	static char	*escapes_quotes = { CHAR_DOLLAR, CHAR_SIMPLE_QUOTE,
					CHAR_DOUBLE_QUOTE, BACKSLASH };
	int			i;

	

}

t_expansion	*expand_double_quote(char *s, char **env)
{
	int			quotes_len;
	t_expansion	*expansion;

	(void)env;
	printf("expand double quotes : %s\n", s);
	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	quotes_len = strlen_quote(s, 0, CHAR_DOUBLE_QUOTE);
	expansion->value = malloc_list(1);
	if (!expansion->value)
	{
		perror("malloc expand_simple_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->value = removed_and_expand_double_quotes(s, &quotes_len);
	if (!expansion->value[0] && quotes_len - 2 > 0)
	{
		perror("malloc expand_sdouble_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->size_to_remove = strlen_quote(s, 0, CHAR_DOUBLE_QUOTE);;
	return (NULL);
}
