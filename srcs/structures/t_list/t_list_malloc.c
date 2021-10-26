/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:39:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:53:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Malloc t_list and set all inside to NULL.
*/

char	**malloc_list(int size)
{
	char	**list;

	list = (char **)malloc(sizeof(char *) * (size + 1));
	if (!list)
	{
		perror("malloc_list()");
		return (NULL);
	}
	list[size] = NULL;
	return (list);
}
