/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:59:25 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:25:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Recherche la première occurence de la chaine s2 dans s1.
** limité à len caractères.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] && len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			++j;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		++i;
	}
	return (NULL);
}
