/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:10:08 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/30 13:11:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un long long int en chaine de caractère
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

char			*ft_lltoa(long long int n)
{
	unsigned long long int	nbr;
	int						size;
	char					*dst;

	nbr = n < 0 ? (unsigned long long int)-n : (unsigned long long int)n;
	size = ft_intlen(nbr) + (n < 0);
	if (!(dst = malloc(sizeof(*dst) * (size + 1))))
		return (NULL);
	dst[size] = '\0';
	if (n < 0)
		dst[0] = '-';
	if (n == 0)
		dst[0] = '0';
	while (nbr)
	{
		dst[--size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (dst);
}
