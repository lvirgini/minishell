/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:19:48 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 13:22:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue la memoire pour (count) objets de taille (size).
*/

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	size_t			i;
	size_t			max;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	max = count * size;
	ptr = (char *)malloc(max);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < max)
		ptr[i++] = 0;
	return (ptr);
}
