/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:44:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 14:25:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
** returns the number corresponding to the expansion function
*/

static int	which_expansion(char c)
{
	static	char expand_char[NB_EXPANDER + 1] = 
		{CHAR_DOLLAR, CHAR_DOUBLE_QUOTE, CHAR_SIMPE_QUOTE, '\0'};

	return (ft_strchr_len(expand_char, c));
}

/*
** sending to the good expansion function
*/

t_expansion	*get_expansion(char *s, char **env)
{
	static const t_ft_expand func[NB_EXPANDER] =
		{expand_dollar, expand_double_quote, expand_simple_quote};

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
