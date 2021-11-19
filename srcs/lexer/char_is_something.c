/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_something.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:52:35 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/18 16:05:42 by lvirgini         ###   ########.fr       */
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
int	is_metacharacter(char c)
{
	int			i;
	static char	metacharacter[NB_METACHARACTER + 1] = {
	[FT_WORD] = ' ',
	[FT_SIMPLE_QUOTE] = CHAR_SIMPE_QUOTE,
	[FT_DOUBLE_QUOTE] = CHAR_DOUBLE_QUOTE,
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
}*/

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
