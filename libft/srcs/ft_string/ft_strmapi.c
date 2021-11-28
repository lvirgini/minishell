/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:21:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:33:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Applique la fonction f à chaque caractère de la chaine (*s).
** Créer une nouvelle chaine avec malloc résultant des applications
** successive de f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*dest;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		++len;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (i < len)
	{
		dest[i] = f(i, s[i]);
		++i;
	}
	return (dest);
}
