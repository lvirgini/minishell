/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:01:05 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/03 15:21:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	Recherche un caractère (c) dans une chaine de caratere (*s).
** 	Renvoie l'index de la première occurence, sinon -1;
*/

int	ft_strchr_len(const char *s, int c)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}
