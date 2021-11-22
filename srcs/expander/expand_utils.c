/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:44:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 20:25:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** returns the number corresponding to the expansion function
*/

static int	which_expansion(char c)
{
	static char	expand_char[NB_EXPANDER + 1] = {
		CHAR_DOLLAR, CHAR_DOUBLE_QUOTE, CHAR_SIMPLE_QUOTE, '\0'};

	return (ft_strchr_len(expand_char, c));
}

/*
** sending to the good expansion function
*/

t_expansion	*get_expansion(char *s, char **env)
{
	static const t_ft_expand	func[NB_EXPANDER] = {
		expand_dollar_in_argv, expand_double_quote, expand_simple_quote};

	return (func[which_expansion(*s)](s, env));
}

/*
** return true if is an expansion character
*/
t_bool	is_expansion(char c)
{
	if (which_expansion(c) != -1)
		return (true);
	return (false);
}

/*
**	For argv : count nb split for expand argv
**	if expand->value is multiple : it must be split in 
**	multiple argument.
*/

size_t	count_expansion_split(t_expansion *expansion)
{
	size_t	count;
	size_t	split;

	count = 0;
	while (expansion)
	{
		split = listlen(expansion->value);
		if (split > 1)
			count += split - 1;
		expansion = expansion->next;
	}
	return (count);
}

/*
** return true or false if string need an expansion
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
