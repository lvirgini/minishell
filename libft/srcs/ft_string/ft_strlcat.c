/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:49:30 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/23 17:28:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Concatène src apres dst avec pour taille maximale de dst : size.
** Protège dst en la terminant par \0.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dstlen;
	unsigned int	j;
	unsigned int	srclen;

	dstlen = 0;
	j = 0;
	srclen = 0;
	while (dst[dstlen])
		++dstlen;
	while (src[srclen])
		++srclen;
	if (dstlen >= size)
		return (size + srclen);
	srclen = size <= dstlen ? srclen + size : srclen + dstlen;
	while (src[j] && dstlen + 1 < size)
		dst[dstlen++] = src[j++];
	dst[dstlen] = '\0';
	return (srclen);
}
