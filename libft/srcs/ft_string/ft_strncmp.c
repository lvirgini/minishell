/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:43:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:35:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare les (n) premiers caractères des deux chaines (*s1) et (*s2).
**	Renvoie la différence ASCII des deux chaines.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0 || !s1 || !s2)
		return (0);
	if (!(*s1) || *s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strncmp(++s1, ++s2, --n));
}
