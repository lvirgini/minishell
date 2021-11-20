/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 15:21:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dollar
   name   A  word  consisting  only  of alphanumeric characters and under‐
          scores, and beginning with an alphabetic character or an  under‐
          score.  Also referred to as an identifier.
*/

size_t	dollar_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isalnum(s[i] || s[i] == '_')))
		i++;
	return (i);
}

char	isolate_key(char *s, t_expansion *expansion)
{
	int		len;
	char	end_of_key;

	len = dollar_len(s);
	expansion->size_to_remove = len + 1;
	end_of_key = s[len];
	s[len] = '\0';
	return (end_of_key);
}

t_expansion	*expand_dollar(char *s, char **env)
{
	printf("expand dollar : %s\n", s);

	t_expansion	*expansion;
	char		*value;
	char		end_of_key;

	expansion = malloc_expansion();
	if (!expansion)
		return (NULL);
	if (s[1] == '\0')
	{
		expansion->size_to_remove = 1;
		expansion->value = ft_split_set(s, STR_ESCAPE);
	}
	if (ft_isalnum(s[1]))
	{
		expansion->size_to_remove = 2;
		expansion->value = ft_split_set("", STR_ESCAPE);
	}
	// if s[1] == "?"
	else
	{
		end_of_key = isolate_key(s + 1, expansion);
		value = get_env_value(env, s + 1);
		if (!value)
			expansion->value = ft_split_set("", STR_ESCAPE); // a verifier pour affichage multi null value
		else
			expansion->value = ft_split_set(value, STR_ESCAPE);
		s[expansion->size_to_remove] = end_of_key;
	}
	return (expansion);
}
/*
char	**expand_dollar(char *str, char **env)
{
	char		**split_expansion;
	char		*value;

	if (str[1] == '\0')
		split_expansion = ft_split_set(str, STR_ESCAPE);
	else
	{
		value = get_env_value(env, str + 1);
		if (!value)
			split_expansion = ft_split_set("", STR_ESCAPE); // a verifier pour affichage multi null value
		else
			split_expansion = ft_split_set(value, STR_ESCAPE);
	}
	return (split_expansion);
}
*/