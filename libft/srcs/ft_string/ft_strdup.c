/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:50:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:32:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** retourne un pointeur sur une nouvelle chaîne de caractères qui est dupliquée
** depuis s. La mémoire occupée par cette nouvelle chaîne est obtenue
** en appelant malloc.
*/

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*dst;

	i = 0;
	while (s[i])
		++i;
	dst = (char *)malloc(sizeof(*s) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

/*
** retourne un pointeur sur une nouvelle chaîne de caractères qui est dupliquée
** depuis s avec au plus (max) octets en terminant par \0.
** La mémoire occupée par cette nouvelle chaîne est obtenue en appelant malloc.
** Remplis de \0 si src_len < len
*/

char	*ft_strdup_max(const char *s, size_t max)
{
	size_t		i;
	char		*dst;

	dst = (char *)malloc(sizeof(*s) * (max + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < max)
	{
		dst[i] = s[i];
		i++;
	}
	while (i <= max)
		dst[i++] = '\0';
	return (dst);
}
