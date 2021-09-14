/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:34:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:12:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Copie n octets depuis la zone mémoire src vers la zone mémoire dest.
** preferez memmove qui verifie l'emplacement de la memoire afin que
** les deux zones puissent se chevaucher.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest || src)
		while (n-- > 0)
			*d++ = *s++;
	return (dest);
}
