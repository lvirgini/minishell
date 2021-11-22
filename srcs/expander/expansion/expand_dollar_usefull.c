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

t_expansion *expand_dollar_in_double_quotes(char *s, char **env, int *len)
{
	t_expansion	*expansion;
	t_expansion	*to_add;
	size_t		i;
	
	i = 1;
	expansion = NULL;
	while (s[i])
	{
		if (s[i] == CHAR_DOLLAR && s[i - 1] != BACKSLASH)
		{
			to_add = expand_dollar(s + i, env, true);
			if (!to_add)
			{
				free_list_expansion(expansion);
				return (NULL);
			}			
			to_add->start_of_the_expand = i;
			i += to_add->size_to_remove;
			*len += ft_strlen(to_add->value[0] - to_add->size_to_remove);
			expansion = add_back_expansion(expansion, to_add);
		}
		else
		{
			*len += 1;
			i++;
		}
	}
	return (expansion);
}