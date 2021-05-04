/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:48:53 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 15:24:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Supprime et libère la memoire de *lst et de tous les éléments qui suivent.
** Le pointeur initiale est mis a NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*next;

	l = *lst;
	while (l)
	{
		next = l->next;
		del(l->content);
		free(l);
		l = next;
	}
	*lst = NULL;
}
