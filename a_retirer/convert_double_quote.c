/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:41:48 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/15 13:10:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//// A FAIRE //

//// attention aux \$truc = $truc
//// attention a export TRUC=$CHOUETTE : TRUC=valeur de CHOUETTE et non genre un pointeur

/*
** Double quote convertor : 
**
**	if \ and special after : escape character after ‘$’, ‘`’, ‘"’, ‘\’, or newline.
**			\\ = \		92 92 = 92
**			\' = '		92 34 = 34
**			\" = "		92 39 = 39
**			\n = newline


mini@debian:~/42/minishell$ echo test \| test  NOPE mais ca veut dire que bash convertis
soit au niveau du token soit juste avant de faire le parsing
test | test
*/

/*
static size_t	strlen_without_escape_char(const char *escape, char *s)
{
	size_t	src_len;
	size_t	dst_len;
	int		nb_variables;
	
	src_len = 0;
	dst_len = 0;
while (s[src_len])
	{
		if (s[src_len] == '$')
		{
			nb_variables++;
			while (nb_)
		}
		if (s[src_len] == '\\' && s[src_len + 1] && ft_strchr(escape, (int)s[src_len + 1]))
			src_len++;
		src_len++;
		dst_len++;
	}
	return (dst_len);
}

static char *strcpy_without_escape_char(const char *escape, char *s, char *dst)
{
	size_t	src_len;
	size_t	dst_len;
	char	**variable;
	
	src_len = 0;
	dst_len = 0;
	while (s[src_len])
	{
		if (s[src_len] == '$')
		{

		}
		if (s[src_len] == '\\' && s[src_len + 1] && ft_strchr(escape, (int)s[src_len + 1]))
			src_len++;
		dst[dst_len] = s[src_len];
		src_len++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dst);
}
*/