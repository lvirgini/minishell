/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:34:22 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 15:42:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 	Recherche un caractère (c) dans une chaine de caratère (*s).
** 	Retourne un pointeur sur la première occurence.
*/

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s && *s)
		s++;
	return ((char)c != *s ? NULL : (char *)s);
}
