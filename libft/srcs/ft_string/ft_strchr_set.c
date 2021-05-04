/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:29:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/13 15:31:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Recherche si *s contient un des caractères de la chaine *set.
** retourne un pointeur sur la premiere occurence, ou NULL si non trouvé.
*/

char	*ft_strchr_set(const char *s, const char *set)
{
	if (!set[0])
		return ((char*)s);
	while (*s)
	{
		if (ft_strchr(set, *s))
			return ((char*)s);
	}
	return (NULL);
}
