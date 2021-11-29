/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:26:04 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/28 15:45:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_integer_size(int n)
{
	unsigned int	unsigned_nbr;
	size_t			size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	unsigned_nbr = ft_abs(n);
	while (unsigned_nbr > 0)
	{
		unsigned_nbr /= 10;
		size++;
	}
	return (size);
}

static void	get_str_from_int(char *dst, int n, size_t size)
{
	unsigned int	unsigned_nbr;

	dst[size] = '\0';
	unsigned_nbr = (unsigned int)ft_abs(n);
	while (size-- > 0)
	{
		dst[size] = unsigned_nbr % 10 + '0';
		unsigned_nbr /= 10;
	}
	if (n < 0)
		dst[0] = '-';
}

char	*ft_itoa(int n)
{
	size_t		size;
	char		*dst;

	size = get_integer_size(n);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	get_str_from_int(dst, n, size);
	return (dst);
}
