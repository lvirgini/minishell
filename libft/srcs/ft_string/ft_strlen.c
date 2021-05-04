/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:39:45 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 16:41:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 	Renvoie le nombre de caratère dans la chaine (*s)
** 	SANS compter le dernier octet nul : "\0"
*/

size_t		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
