/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:03:55 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 12:30:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return a list resultant
*/
/*
char	**list_join(char **first, char **second)
{
	size_t	len;
	size_t	len_first;
	char	**join;

	if (!first)
	{
		if (!second)
			return (NULL);
		return (list_dup(second));
	}
	if (!second)
		return (list_dup(first));
	len_first = listlen(first);
	len = len_first + listlen(second);
	join = malloc_list(len);
	if (!list_cpy(join, first) || !list_cpy(join + len_first, second))
	{
		free_list(join);
		return (NULL);
	}
	return (join);
}
*/