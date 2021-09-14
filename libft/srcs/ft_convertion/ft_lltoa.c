/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:10:08 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 21:34:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un long long int en chaine de caractère
** Utilise Malloc
*/

static int	ft_intlen(unsigned long long int n)
{
	size_t	i;

	i = 1;
	while (n > 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_lltoa(long long int n)
{
	unsigned long long int	nbr;
	size_t					size;
	char					*dst;

	nbr = ft_llabs(n);
	size = ft_intlen(nbr) + (n < 0);
	dst = malloc(sizeof(*dst) * (size + 1));
	if (dst == NULL)
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
