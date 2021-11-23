/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:37:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 16:41:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char	*expand_dquotes_variable(char *s)
{
	size_t	i;
	char	*result;
	char	*value;

	i = 0;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR)
		{
			value = isolate_dquotes_variable_value(s + i);
		}
	}
}

char	*expand_double_quote(char *s)
{

	s = expand_dquotes_variable(s);
	size_t len_after_expand;
	char	*result;
	int i;
	int	j;

	i = 0;
	j = 0;

	while (s[i])
	{
		while (s[i] && s[i] != CHAR_DOLLAR)
		{
			if (s[i] == CHAR_ESCAPE)
				i++;
			i++;
			len_after_expand++;
		}
		join_expand(result, s, i, len);
		if (s[i] == CHAR_DOLLAR)
			join_dquote_variable(result, s, &i, len)
	}

	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR)
		{
			result = dquotes_dollar_expand(result, s, &i);
			if (!result)
			{
				free(s);
				free(result);
				return (NULL);
			}
		}	
		if (s[i] == CHAR_ESCAPE)
			i++;
		i++;
	}

}*/