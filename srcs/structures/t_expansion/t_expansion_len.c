/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:31:29 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 21:40:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	expansion_len(t_expansion *expansion)
{
	size_t	len;

	len = 0;
	while (expansion)
	{
		expansion = expansion->next;
		len++;
	}
	return (len);
}
