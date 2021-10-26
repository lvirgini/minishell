/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:44:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:51:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	duplicate_list(char **list, char **old_list, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		list[i] = ft_strdup(old_list[i]);
		if (!list[i])
		{
			perror("malloc in duplicate_list()");
			free_n_list(list, i);
			return (FAILURE);
		}
		i++;
	}
	list[i] = NULL;
	return (SUCCESS);
}
