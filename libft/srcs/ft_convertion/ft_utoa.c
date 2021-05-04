/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:56:38 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 18:11:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un unsigned int en chaine de caractère
** Utilise Malloc
*/

static int		ft_intlen(unsigned int n)
{
	unsigned int i;

	i = 1;
	while (n /= 10)
		++i;
	return (i);
}

char			*ft_utoa(unsigned int n)
{
	int						size;
	char					*dst;

	size = ft_intlen(n);
	if (!(dst = malloc(sizeof(*dst) * (size + 1))))
		return (NULL);
	dst[size] = '\0';
	if (n == 0)
		dst[0] = '0';
	while (n)
	{
		dst[--size] = n % 10 + '0';
		n /= 10;
	}
	return (dst);
}
