/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:56:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 17:54:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un unsigned int en chaine de caractère
** Utilise Malloc
*/

static int	ft_intlen(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	size_t		size;
	char		*dst;

	size = ft_intlen(n);
	dst = malloc(sizeof(*dst) * (size + 1));
	if (dst == NULL)
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
