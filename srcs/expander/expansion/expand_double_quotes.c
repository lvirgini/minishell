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
*/

size_t	strlen_without_double_quotes(char *s, char *escape_quotes)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == BACKSLASH && ft_strchr(escape_quotes, s[len + 1]))
			len++;
		len++;
	}
	return (len);

}


char	*removed_and_expand_double_quotes(char *s, int	*len, char **env)
{
	static char	escape_quotes[] = {CHAR_DOLLAR, CHAR_DOUBLE_QUOTE, BACKSLASH,
					GRAVE_ACCENT, '\0'};
	int			i;
	int			j;
	char		*result;
	t_expansion	*expansion;

	expansion = NULL;
	if (ft_strchr(s, CHAR_DOLLAR))
	{
		expansion = expand_dollar_in_double_quotes(s, env, len);
		if (!expansion)
			return (NULL);
	}
	else
		*len = strlen_without_double_quotes(s, escape_quotes);

	result = (char *)malloc(sizeof(char) * (*len + 1));
//		* (strlen_without_double_quotes(s, escape_quotes) + 1));
	if (!result)
	{
		free_list_expansion(expansion);
		return (NULL);
	}

	i = 1;
	j = 0;
	while (s[i + 1] && j < *len)
	{
		if (s[i] == '$')
		{
			ft_strcpy(result + j, expansion->value[0]);
			i += expansion->size_to_remove;
			j = ft_strlen(expansion->value[0]);
			expansion = expansion->next;
		}
		else 
		{
			if (s[i] == BACKSLASH && ft_strchr(escape_quotes, s[i + 1]))
				i++;
			result[j++] = s[i++];
		}
	}
	result[j] = '\0';
	return (result);
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
	quotes_len = 0;
	expansion->value = malloc_list(1);
	if (!expansion->value)
	{
		perror("malloc expand_simple_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->value[0] = removed_and_expand_double_quotes(s, &quotes_len, env);
	if (!expansion->value[0] && quotes_len > 0)
	{
		perror("malloc expand_sdouble_quotes()");
		free(expansion);
		return (NULL);
	}
	expansion->size_to_remove = quotes_len;
	return (expansion);
}
