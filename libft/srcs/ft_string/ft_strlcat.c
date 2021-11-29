/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:49:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/21 15:24:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatène src apres dst avec pour taille maximale de dst : size.
** Protège dst en la terminant par \0.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (size + srclen);
	if (size <= dstlen)
		srclen += size;
	else
		srclen += dstlen;
	i = 0;
	while (src[i] && dstlen + 1 < size)
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (srclen);
}
