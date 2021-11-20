/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_struct_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:35:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 14:38:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*struct_add_front(void *void_struct, void *void_to_add)
{
	t_struct	*structure;
	t_struct	*to_add;

	structure = (t_struct *)void_struct;
	to_add = (t_struct *)void_to_add;
	
	to_add->next = structure;
	return ((void *)to_add);
}
