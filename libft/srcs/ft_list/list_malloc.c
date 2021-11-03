/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:39:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:10:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Malloc t_list and set all inside to NULL.
*/

char	**malloc_list(int size)
{
	char	**list;

	if (size < 0)
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (size + 1));
	if (!list)
		return (NULL);
	list[size] = NULL;
	return (list);
}
