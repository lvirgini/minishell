/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:43:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 11:35:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** free all list
*/

void	free_list(char **list)
{
	size_t		i;

	i = 0;
	if (list)
	{
		while (list[i])
		{
			free(list[i]);
			list[i] = NULL;
			i++;
		}
		free(list);
	}
}

/*
** free char ** until nb
** ONLY USED FOR MALLOC ERROR IN DUPLICATION LIST
** ex: 
**		
**	char **list && char **result
**		while (list[i])
**		{
**			result[i] = strdup(list[i])
**			if (result[i] == NULL)
**				free_n_list(result, i);
**		}
*/

void	free_n_list(char **list, size_t max)
{
	size_t		i;

	if (!list)
		return ;
	i = 0;
	while (i < max && list[i])
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
}
