/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:34:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/22 14:46:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare les caractères des deux chaines (*s1) et (*s2).
**	Renvoie la différence ASCII des deux chaines.
** 0 si identiques.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!*s1 || *s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strcmp(++s1, ++s2));
}
