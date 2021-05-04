/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:34:12 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 18:10:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare les caractères des deux chaines (*s1) et (*s2).
**	Renvoie la différence ASCII des deux chaines.
** 0 si identiques.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	return (!(*s1) || *s1 != *s2
			? (unsigned char)*s1 - (unsigned char)*s2
			: ft_strcmp(++s1, ++s2));
}
