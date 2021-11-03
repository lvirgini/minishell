/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:43:42 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/28 13:16:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** list_str is char ** malloc with NULL for last char *.
*/

size_t	listlen(char **list)
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
