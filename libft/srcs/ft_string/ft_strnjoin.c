/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:10:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/21 11:17:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*dest;

	if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup_max(s2, n));
	len = ft_strlen(s1) + n;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && j < n)
		dest[j++] = s2[i++];
	while (j < n)
		dest[j] = '\0';
	dest[j] = '\0';
	return (dest);
}
