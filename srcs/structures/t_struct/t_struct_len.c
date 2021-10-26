/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_struct_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:24:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 16:25:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	struct_len(void *struct_first)
{
	size_t		len;
	t_struct	*structure;

	len = 0;
	structure = (t_struct *)struct_first;
	while (structure)
	{
		structure = structure->next;
		len++;
	}
	return (len);
}
