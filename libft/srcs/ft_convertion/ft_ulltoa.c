/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:11:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 17:59:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversion d'un unsigned long long int en chaine de caractère
** Utilise Malloc
*/

static int	ft_longlonglen(unsigned long long int n)
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

char	*ft_ulltoa(unsigned long long int n)
{
	int						size;
	char					*dst;

	size = ft_longlonglen(n);
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
