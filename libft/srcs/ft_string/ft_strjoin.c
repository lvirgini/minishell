/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:35:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 19:32:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_str_is_null(char const *s1, char const *s2)
{
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	return (NULL);
}
/*
**	Alloue avec malloc et retourne une nouvelle chaine
**	Résultat de la concaténation de (*s1) et (*s2) dans cet ordre.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*dest;

	dest = (if_str_is_null(s1, s2));
	if (dest)
		return (dest);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

/*
** strjoin avec free(s1);
*/

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char *dst;

	dst = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	s1 = NULL;
	return (dst);
}
