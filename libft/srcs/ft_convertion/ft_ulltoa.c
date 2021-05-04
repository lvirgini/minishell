/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:11:45 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/30 13:12:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un unsigned long long int en chaine de caractère
** Utilise Malloc
*/

static int		ft_intlen(unsigned long long int n)
{
	unsigned int i;

	i = 1;
	while (n /= 10)
		++i;
	return (i);
}

char			*ft_ulltoa(unsigned long long int n)
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
