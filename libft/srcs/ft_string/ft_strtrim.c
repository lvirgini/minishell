/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:24:00 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 16:00:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Retourne une copie de la chaine *s sans les caractères présents
** au debut et à la fin de *s1. set contient les caractères à trimer.
** Pas de + 1 au malloc car end compte le \0.
*/

#include <stdlib.h>

static int		ft_len(char const *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int		ft_check_start(char const *s, char const *set)
{
	int start;
	int i;

	i = 0;
	start = 0;
	while (set[i])
	{
		if (*s == set[i++])
		{
			s++;
			i = 0;
			start++;
		}
	}
	return (start);
}

static int		ft_check_end(char const *s, char const *set, int len)
{
	int i;
	int tmp;

	i = 0;
	tmp = len;
	while (set[i])
	{
		if (s[len] == set[i++])
		{
			len--;
			i = 0;
		}
	}
	if (len < 0)
		return (tmp);
	return (len);
}

char			*ft_strtrim(char const *s, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;
	unsigned int	i;
	char			*res;

	if (!s || !set)
		return ((char *)s);
	i = 0;
	len = ft_len(s);
	start = ft_check_start(s, set);
	if (start == len)
		if (!(res = malloc(sizeof(*res))))
			return (NULL);
	if (start != len)
	{
		end = ft_check_end(s, set, len - 1);
		end++;
		if (!(res = malloc(sizeof(*res) * (end - start + 1))))
			return (NULL);
		while (start < end)
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
