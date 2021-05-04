/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:28:22 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 15:23:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute l'élément new à la fin de la liste.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	l = *alst;
	if (l == NULL)
		*alst = new;
	else
	{
		while (l->next)
			l = l->next;
		l->next = new;
	}
}
