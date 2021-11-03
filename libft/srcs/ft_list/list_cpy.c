/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:20:56 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:09:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copy src in dst. (using malloc)
*/

int	list_cpy(char **dst, char **src)
{
	int		i;

	if (!dst || !src)
		return (FAILURE);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			free_n_list(dst, i);
			return (FAILURE);
		}
		i++;
	}
	return (i);
}

/*
** copy src in dst, until max index of src. (using malloc)
*/

int	list_ncpy(char **dst, char **src, size_t max)
{
	size_t		i;
	size_t		len;

	if (!dst || !src || max == 0)
		return (FAILURE);
	len = listlen(src);
	if (len < max)
		max = len;
	i = 0;
	while (i < max && src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
			return (FAILURE);
		i++;
	}
	return ((int)i);
}
