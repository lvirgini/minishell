/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:55:52 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:21:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** retourne la longueur de s tant qu'il n'y a pas d'element similaire a set.
*/

size_t	ft_strlen_set(const char *s, const char *set)
{
	size_t	len;

	len = 0;
	while (!ft_strchr(set, s[len]))
		len++;
	return (len);
}
