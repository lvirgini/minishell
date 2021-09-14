/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:35:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:13:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** copie n octets depuis la zone mémoire src vers la zone mémoire dest.
** Les deux zones peuvent se chevaucher.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest < src)
		while (n-- > 0)
			*d++ = *s++;
	else if (dest > src)
	{
		d += n;
		s += n;
		while (n-- > 0)
			*--d = *--s;
	}
	return (dest);
}
