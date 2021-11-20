/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:34:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 14:24:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
t_bool	need_expand_str(char *str)
{
	if (str)
	{
		if (str[0] == CHAR_DOUBLE_QUOTE
			|| str[0] == CHAR_SIMPE_QUOTE
			|| str[0] == CHAR_DOLLAR)
			return (true);
	}
	return (false);
}*/
/*
char	**expand_list(char *str, char **env)
{
	if (str)
	{
		if (*str == CHAR_DOLLAR)
			return (expand_dollar(str, env));
	/*	else if (*str == CHAR_DOUBLE_QUOTE)
			return (expand_double_quote(str));
		else if (*str == CHAR_SIMPE_QUOTE)
			return (expand_simple_quote(str));
	}
	return (NULL);
}
*/


t_bool	need_expand(char *s)
{
	size_t	i;

	if (!s)
		return (false);
	i = 0;
	while (s[i])
	{
		if (is_expansion(s[i]))
			return (true);
		i++;
	}
	return (false);
}