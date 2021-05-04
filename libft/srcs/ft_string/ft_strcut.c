/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:34:12 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/03 15:02:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Coupe dans dst la chaine src jusqu'au (n)eme octet tant que src existe.
** retourne la taille de dst.
*/

char	*ft_strcut(char *s, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (n > 0)
	{
		while (i < (n - 1) && s[i])
			i++;
	}
	s[i] = '\0';
	return (s);
}
