/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:58:29 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 16:30:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Mise à 0 des (n) premiers octets suivant (*s).
*/

void	*ft_bzero(void *s, size_t n)
{
	char *d;

	d = s;
	if (n > 0)
		while (n--)
			*d++ = 0;
	return (s);
}
