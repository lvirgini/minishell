/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:49:38 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/13 15:27:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creer un nouvel élément de liste avec la variable content
** Utilise Malloc
*/

t_list		*ft_lstnew(void *content)
{
	t_list *l;

	if (!(l = (t_list *)malloc(sizeof(l))))
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}
