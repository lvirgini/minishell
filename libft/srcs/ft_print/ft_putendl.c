/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:39:06 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 13:18:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Écrit La chaine de caractères sur la sortie standard
** suivie d’un retour à la ligne.
*/

void	ft_putendl(char *s)
{
	if (s)
	{
		ft_putstr(s);
		write(1, "\n", 1);
	}
}
