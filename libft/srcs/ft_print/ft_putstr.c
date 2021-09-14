/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:16:34 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:17:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit la chaine de caractère (*s)  sur la sortie standard.
*/

void	ft_putstr(char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			++i;
		write(1, s, i);
	}
}
