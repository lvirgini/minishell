/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:09:45 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/23 12:39:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creer une nouvelle liste résultant des applications successives de f.
** applique la fonction f au contenu de chaque élément.
** del tout si problème.
** Utilise Malloc
*/

static void		ft_delet_all(t_list *l, void (*del)(void *))
{
	t_list	*save_l;
	t_list	*next;

	save_l = l;
	while (save_l)
	{
		next = save_l->next;
		del(save_l->content);
		free(save_l);
		save_l = next;
	}
}

static t_list	*ft_tr(t_list *lst, t_list *l, void *(*f)(void *),
void (*del)(void *))
{
	if (!(l = (t_list *)malloc(sizeof(l))))
	{
		ft_delet_all(l, del);
		return (NULL);
	}
	l->content = f(lst->content);
	return (l);
}

static void		ft_initialize(t_list **a, t_list **b, t_list **c)
{
	*a = NULL;
	*b = NULL;
	*c = NULL;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*l;
	t_list	*tmp;
	t_list	*save_l;

	ft_initialize(&l, &tmp, &save_l);
	if (!lst || (!(l = ft_tr(lst, l, f, del))))
		return (NULL);
	save_l = l;
	while ((lst = lst->next))
	{
		if (!(tmp = ft_tr(lst, tmp, f, del)))
			return (NULL);
		l->next = tmp;
		l = l->next;
	}
	return (save_l);
}
