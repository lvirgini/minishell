/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:12:51 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 15:34:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compte le nombre d'élément que contient la liste.
*/

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	unsigned int i;

	i = 0;
	while (lst && i++)
		lst = lst->next;
	return (i);
}
