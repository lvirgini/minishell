/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_duplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:44:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 14:20:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate complete char **list
*/

char	**list_dup(char **src)
{
	size_t	len;
	char	**dst;

	if (!src)
		return (NULL);
	len = listlen(src);
	dst = malloc_list(len);
	if (dst)
	{
		if (list_cpy(dst, src) == FAILURE)
			return (NULL);
		return (dst);
	}
	return (dst);
}

/*
** Duplicate no more than <max> index of char **list
*/

char	**list_ndup(char **src, size_t max)
{
	size_t	len;
	char	**dst;

	if (!src)
		return (NULL);
	len = listlen(src);
	if (len < max)
		max = len;
	dst = malloc_list(max);
	if (dst)
	{
		if (list_ncpy(dst, src, max) == FAILURE)
			return (NULL);
		return (dst);
	}
	return (dst);
}
