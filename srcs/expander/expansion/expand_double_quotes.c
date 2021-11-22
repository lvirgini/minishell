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

size_t	strlen_without_double_quotes(char *s, char *escape_quotes)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == BACKSLASH && ft_strchr(escape_quotes, [len + 1])
			len++;
		len++;
	}
	return (len);

}


char	*removed_and_expand_double_quotes(char *s, int	quotes_len)
{
	static char	escapes_quotes[] = {CHAR_DOLLAR, CHAR_DOUBLE_QUOTE, BACKSLASH,
					GRAVE_ACCENT, '\0'};
	size_t		i;
	size_t		j;
	char		*result;

	result = (char *)malloc(sizeof(char) 
		* (strlen_without_double_quotes(s, escape_quotes) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == BACKSLASH && ft_strchr(escape_quotes, [i + 1])
			i++;
		result[j++] = s[i++];
	}
	result[j] = '\0';
	reurn (result);
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
	quotes_len = strlen_double_quote(s, 0);
	expansion->value = malloc_list(1);
	if (!expansion->value)
	{
		perror("malloc expand_simple_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->value = removed_and_expand_double_quotes(s, quotes_len);
	if (!expansion->value[0] && quotes_len - 2 > 0)
	{
		perror("malloc expand_sdouble_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->size_to_remove = strlen_double_quote(s, 0);
	return (NULL);
}
