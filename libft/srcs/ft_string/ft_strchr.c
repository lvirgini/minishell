/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:34:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:38:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 	Recherche un caractère (c) dans une chaine de caratère (*s).
** 	Retourne un pointeur sur la première occurence.
*/

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s && *s)
		s++;
	if ((char)c != *s)
		return (NULL);
	return ((char *)s);
}

char	*ft_strnchr(const char *s, int c, int len_max)
{
	int		i;

	i = 0;
	while (i < len_max && s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}