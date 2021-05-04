/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:35:37 by lvirgini          #+#    #+#             */
/*   Updated: 2019/10/31 18:56:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i++] || (i = 0) != 0)
		len++;
	while (s2[i++] || (i = 0) != 0)
		len++;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (s1[i] || (i = 0) != 0)
		dest[j++] = s1[i++];
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}
