/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_usefull.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:31:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 19:54:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand dollar[name]
**	name : A  word  consisting  only  of alphanumeric characters and 
**	under‐scores and beginning with an alphabetic character or an  under‐score.
**	Also referred to as an identifier.
*/

size_t	dollar_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !is_expansion(s[i])
		&& (ft_isalnum(s[i]) || s[i] == '_' ))
		i++;
	return (i);
}

t_bool	is_dollar_env_value_syntax(char c)
{
	if (ft_isalpha(c) || c == '_' )
		return (true);
	return (false);
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

t_expansion	*expand_dollar_in_argv(char *s, char **env)
{
	return (expand_dollar(s, env, false));
}

t_expansion *expand_dollar_in_double_quotes(char *s, char **env)
{
	t_expansion	*expansion;
	size_t		i;
	
	i = 1;
	expansion = NULL;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR && s[i - 1] != BACKSLASH)
		{
			expansion = add_back_expansion(expansion, expand_dollar(s, env, true);
			expansion->size_to_remove = i;

		} 
	}
	return (expand_dollar(s, env, true));
}