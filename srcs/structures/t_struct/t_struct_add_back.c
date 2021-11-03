/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_struct_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:07:17 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/27 13:05:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	struct_add_back(void *void_struct, void *void_to_add)
{
	t_struct	*structure;
	t_struct	*to_add;

	structure = (t_struct *)void_struct;
	to_add = (t_struct *)void_to_add;
	while (structure->next)
		structure = structure->next;
	structure->next = to_add;
	//to_add->prev = last;

}

void	struct_list_add_back(void *void_list, void *void_to_add)
{
	t_struct	**list;
	t_struct	*to_add;
	t_struct	*last;

	list = (t_struct **)void_list;
	to_add = (t_struct *)void_to_add;
	if (!*list)
		*list = to_add;
	else
	{
	//	struct_add_back(*list, to_add); //
		last = *list;
		while (last->next)
			last = last->next;
		last->next = to_add;
		to_add->prev = last;
	}
}
