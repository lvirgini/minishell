/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:03:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/08 11:21:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Conversion d'un int en chaine de caractère
** Utilise Malloc
*/

static void		ft_itoatransfert(long int n, int size, int sign, char *dst)
{
	dst[size + 1] = '\0';
	if (n != 0)
	{
		while (n > 0)
		{
			dst[size--] = n % 10 + '0';
			n /= 10;
		}
		if (sign)
			dst[0] = '-';
	}
	else
		dst[0] = '0';
}

char			*ft_itoa(int n)
{
	unsigned long int	i;
	int					sign;
	int					size;
	char				*dst;

	if (n == -2147483648)
	{
		if (!(dst = malloc(sizeof(*dst) * 12)))
			return (NULL);
		ft_itoatransfert(2147483648, 10, 1, dst);
		return (dst);
	}
	i = 10;
	sign = n < 0 ? 1 : 0;
	if ((size = sign) == 1)
		n *= -1;
	while (n / i > 0 && ++size > 0)
		i *= 10;
	if (!(dst = malloc(sizeof(*dst) * (size + 2))))
		return (NULL);
	ft_itoatransfert(n, size, sign, dst);
	return (dst);
}
