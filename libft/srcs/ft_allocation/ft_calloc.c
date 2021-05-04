/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:19:48 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/11 11:53:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue la memoire pour (count) objets de taille (size).
*/

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = malloc(count * size)))
		return (NULL);
	i = 0;
	while (i < (count * size))
		ptr[i++] = 0;
	return (ptr);
}
