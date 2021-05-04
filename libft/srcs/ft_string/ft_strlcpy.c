/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:25:15 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/03 12:16:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Copie src dans dst au plus size octets. protège dst en la finissant par \0.
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!src)
		return (0);
	src_len = 0;
	i = 0;
	while (src[src_len])
		++src_len;
	if (size-- > 0)
	{
		while (size-- && i < (src_len) && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
