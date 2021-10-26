/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:43:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 14:45:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** list_str is char ** malloc with NULL for last char *.
*/

size_t	list_strlen(char **list)
{
	size_t	len;

	len = 0;
	if (list)
	{
		while (list[len])
			len++;
	}
	return (len);
}
