/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:39:14 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:12:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Remplit les n premiers octets de la zone mémoire pointée par s.
** avec l'octet c.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;

	d = s;
	while (n--)
		*d++ = (char)c;
	return (s);
}
