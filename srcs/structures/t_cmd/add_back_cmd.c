/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:15:09 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 13:22:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** add t_cmd at the end of list
*/

void	add_back_cmd(t_cmd **list_cmd, t_cmd *to_add)
{
	t_cmd *last;

	if (!*list_cmd)
		*list_cmd = to_add;
	else
	{
		last = *list_cmd;
		while (last->next)
			last = last->next;
		last->next = to_add;
		to_add->prev = last;
	}
}