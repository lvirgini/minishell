/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_metacharacter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:52:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/10 14:26:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return number of metacharacter if it is, or 0 if not.
** metacharacter is usefull for separate different token in lexer.
*/

int	is_metacharacter(char c)
{
	int			i;
	static char	metacharacter[NB_METACHARACTER + 1] = {
	[FT_WORD] = ' ',
	[FT_SIMPLE_QUOTE] = META_SIMPE_QUOTE,
	[FT_DOUBLE_QUOTE] = META_DOUBLE_QUOTE,
	[FT_PIPE] = META_PIPE,
	[FT_TILD_LEFT] = META_TILD_LEFT, 
	[FT_TILD_RIGHT] = META_TILD_RIGHT, 
	[FT_DOLLAR] = META_DOLLAR};

	i = 1;
	while (i < NB_METACHARACTER + 1)
	{
		if (c == metacharacter[i])
			return (i);
		i++;
	}
	return (FT_WORD);
}
