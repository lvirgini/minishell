/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:05:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:12:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Copie au plus n octets de la zone mémoire src vers la zone mémoire dest,
** s'arrêtant dès qu'elle rencontre le caractère c.
** Renvoie un pointeur sur le caractère immédiatement après c dans la zone dest
** ou NULL si c n'a pas été trouvé dans les n premiers caractères de src.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		*d = *s;
		(*d)++;
		(*s)++;
		if (*d == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
