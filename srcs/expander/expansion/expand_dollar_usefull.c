/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_usefull.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:31:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:33:27 by lvirgini         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (s[i] && !is_expansion(s[i])
		&& (ft_isalnum(s[i]) || s[i] == '_' ))
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
