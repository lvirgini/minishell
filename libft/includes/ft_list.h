/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:15:29 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/06 14:37:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bonus pour le projet de libft.
*/

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct s_list	t_list;

struct			s_list
{
	void			*content;
	struct s_list	*next;
};

/*
** Fonctions traitant les listes (pour le moment bonus de libft)
*/

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
