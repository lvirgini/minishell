/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_something.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:52:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/27 22:26:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return number of metacharacter if it is, or FT_WORD if not.
** metacharacters are useful to separate different tokens in the lexer.
*/

int	is_metacharacter(char c)
{
	int			i;
	static char	metacharacter[NB_METACHARACTER + 1] = {
	[FT_WORD] = ' ',
	[FT_PIPE] = CHAR_PIPE,
	[FT_TILD_LEFT] = CHAR_TILD_LEFT,
	[FT_TILD_RIGHT] = CHAR_TILD_RIGHT};

	i = 1;
	while (i < NB_METACHARACTER + 1)
	{
		if (c == metacharacter[i])
			return (i);
		i++;
	}
	return (FT_WORD);
}

/*
** in minishell operator is only <newline> and pipe
*/

int	is_operator(char c)
{
	int			i;
	static char	operator[2] = {'\n', CHAR_PIPE};

	i = 0;
	while (i < 2)
	{
		if (c == operator[i])
			return (true);
		i++;
	}
	return (false);
}
