/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:10:50 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 16:02:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_str_is_null(char const *s1, char const *s2, size_t n)
{
	if (!s1 && s2)
		return (ft_strdup_max(s2, n));
	if (s1 && !s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*dest;

	dest = if_str_is_null(s1, s2, n);
	if (dest)
		return (dest);
	len = ft_strlen(s1) + n;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && j < len)
		dest[j++] = s2[i++];
	while (j < n)
		dest[j] = '\0';
	dest[j] = '\0';
	return (dest);
}

char	*ft_strnjoin_free(char *s1, char const *s2, size_t n)
{
	char	*dst;

	dst = ft_strnjoin(s1, s2, n);
	if (s1)
		free(s1);
	s1 = NULL;
	return (dst);
}
