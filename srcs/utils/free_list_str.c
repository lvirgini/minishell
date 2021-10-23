/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:35:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 16:01:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free all inside char **
*/

void	free_list_str(char **list_str)
{
	size_t		i;

	if (!list_str)
		return ;
	i = 0;
	while (list_str[i])
	{
		free(list_str[i]);
		list_str[i] = NULL;
		i++;
	}
	free(list_str);
}

/*
** free char ** until nb
** usefull for malloc error.
*/

void	free_n_list_str(char **list_str, size_t nb) 
{
	size_t		i;

	if (!list_str)
		return ;
	i = 0;
	while (i < nb)
	{
		free(list_str[i]);
		list_str[i] = NULL;
		i++;
	}
	free(list_str);
}